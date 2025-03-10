/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/10 12:48:06 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_function(t_thread *philo)
{
	uintmax_t	elapsed_time;

	elapsed_time = current_time() - philo->last_meal_time;
	if (philo->philos->philos_number % 2 != 0)
	{
		pthread_mutex_lock(&philo->philos->general_lock);
		if (philo->philo_num % 2 != 0 && philo->philos->time_to_die
			- elapsed_time > philo->philos->time_to_eat)
		{
			pthread_mutex_unlock(&philo->philos->general_lock);
			usleep(philo->philos->time_to_eat / 2 * 1000);
		}
		else
			pthread_mutex_unlock(&philo->philos->general_lock);
	}
}

int	death_checker(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->philos_number)
	{
		pthread_mutex_lock(&philos->general_lock);
		if (philos->threads[i].next_status == ENOUGH_ROUNDS)
			return (pthread_mutex_unlock(&philos->general_lock), -1);
		if ((current_time()
				- philos->threads[i].last_meal_time) > philos->time_to_die)
		{
			pthread_mutex_unlock(&philos->general_lock);
			pthread_mutex_lock(&philos->general_lock);
			philos->one_death = true;
			pthread_mutex_unlock(&philos->general_lock);
			pthread_mutex_lock(&philos->print_lock);
			printf("%ld %d %s\n", (current_time() - philos->start_time),
				philos->threads[i].philo_num, "dead");
			pthread_mutex_unlock(&philos->print_lock);
			return (-1);
		}
		pthread_mutex_unlock(&philos->general_lock);
		i++;
	}
	return (1);
}

void	*monitor_checker(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	usleep(500);
	while (!philos->one_death && !philos->all_eat)
	{
		if (death_checker(philos) == -1)
			break ;
		usleep(5000);
	}
	return (NULL);
}
