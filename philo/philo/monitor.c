/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/06 14:33:56 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_checker(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->philos_number)
	{
		if (philos->threads[i].next_status == ENOUGH_ROUNDS)
			return (-1);
		pthread_mutex_lock(&philos->general_lock);
		if ((current_time()
				- philos->threads[i].last_meal_time) > philos->time_to_die)
		{
			philos->one_death = true;
			printf("%ld %d %s\n", (current_time()
					- philos->threads[i].start_time),
				philos->threads[i].philo_num, "is dead");
			pthread_mutex_unlock(&philos->general_lock);
			break;
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
			break;
		usleep(5000);
	}
	return (NULL);
}
