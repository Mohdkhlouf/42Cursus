/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/05 14:14:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_all_eat(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->philos_number)
	{
		philos->threads[i].next_status = ENOUGH_ROUNDS;
		i++;
	}
	return (1);
}

int	check_eating_rounds(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philos->general_lock);
	while (i < philos->philos_number && !philos->one_death)
	{
		if ((philos->threads[i].eating_conter >= philos->eating_rounds)
			&& !philos->all_eat)
		{
			philos->all_eating_counter++;
			if (philos->all_eating_counter == philos->philos_number)
			{
				philos->all_eat = true;
				set_all_eat(philos);
			}
		}
		i++;
	}
	pthread_mutex_unlock(&philos->general_lock);
	return (0);
}

void	death_checker(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->philos_number && !philos->one_death)
	{
		pthread_mutex_lock(&philos->general_lock);
		if ((current_time()
				- philos->threads[i].last_meal_time) > philos->time_to_die)
		{
			philos->one_death = true;
			printf("%ld %d %s\n", (current_time()
					- philos->threads[i].start_time),
				philos->threads[i].philo_num, "is dead");
			pthread_mutex_unlock(&philos->general_lock);
			break ;
		}
		pthread_mutex_unlock(&philos->general_lock);
		i++;
	}
}

void	*monitor_checker(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!philos->one_death && !philos->all_eat)
	{
		death_checker(philos);
		check_eating_rounds(philos);
		usleep(5000);
	}
	return (NULL);
}
