/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/23 01:03:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *msg, t_thread *philo, int skip)
{
	if (!philo->philos->one_death || skip == 1)
	{
		pthread_mutex_lock(&philo->philos->print_lock);
		printf("%lld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
		pthread_mutex_unlock(&philo->philos->print_lock);
	}
}
void	check_eating_rounds(t_philo *philos, int *i)
{
	if ((philos->threads[*i].eating_conter >= philos->eating_rounds)
		&& !philos->all_eat)
	{
		philos->all_eating_counter++;
		if (philos->all_eating_counter == philos->philos_number)
			philos->all_eat = true;
	}
}

void	check_deth(t_philo *philos)
{
    int i;

    i = 0;
	while (i < philos->philos_number)
	{
		if ((current_time()
				- philos->threads[i].last_meal_time) > philos->time_to_die)
		{
			philos->one_death = true;
			philos->threads[i].next_status = DEAD;
			pthread_mutex_unlock(&philos->print_lock);
			// return (0);
		}
		check_eating_rounds(philos, &i);
		i++;
	}
}

void	*philos_monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philos->print_lock);
        check_deth(philos);
		pthread_mutex_unlock(&philos->print_lock);
		usleep(1000);
	}
	return (0);
}
