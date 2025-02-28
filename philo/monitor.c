/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/28 17:31:45 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eating_rounds(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philos->general_lock);
	while (i < philos->philos_number)
	{
		if ((philos->threads[i].eating_conter >= philos->eating_rounds)
			&& !philos->all_eat)
		{
			philos->all_eating_counter++;
			if (philos->all_eating_counter == philos->philos_number)
			{
				philos->all_eat = true;
			}
		}
		i++;
	}
	pthread_mutex_unlock(&philos->general_lock);
	return (0);
}

int	check_death(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philos->general_lock);
	while (i < philos->philos_number && !philos->one_death)
	{
		if ((current_time()
				- philos->threads[i].last_meal_time) >= philos->time_to_die)
		{
			philos->one_death = true;
			pthread_mutex_lock(&philos->print_lock);
			printf("%ld %d %s\n", (current_time()
					- philos->threads[i].start_time),
				philos->threads[i].philo_num, "is dead");
			pthread_mutex_unlock(&philos->print_lock);
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&philos->general_lock);
	return (0);
}

void	print_message(char *msg, t_thread *philo, int skip)
{
	check_death(philo->philos);
	check_eating_rounds(philo->philos);
	pthread_mutex_lock(&philo->philos->general_lock);
	if (!philo->philos->one_death || skip == 1)
	{
		pthread_mutex_lock(&philo->philos->print_lock);
		printf("%ld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
		pthread_mutex_unlock(&philo->philos->print_lock);
	}
	pthread_mutex_unlock(&philo->philos->general_lock);
}

void	exit_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos_number)
	{
		pthread_join(philo->threads[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < philo->philos_number)
	{
		pthread_mutex_destroy(&philo->threads[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->print_lock);
	i = 0;
	free(philo->threads);
}
