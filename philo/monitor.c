/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/20 01:34:08 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *msg, t_thread *philo, int skip)
{
	// if some body has died, then dont print.
	pthread_mutex_lock(&philo->philos->print_lock);
	if (!philo->philos->one_death || skip == 1)
	{
		printf("%lld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
	}
	pthread_mutex_unlock(&philo->philos->print_lock);

}

void	*philos_monitor(void *arg)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)arg;
	while (1 && !philos->one_death)
	{
		while (i < philos->philos_number)
		{
			if ((current_time()
					- philos->threads[i].last_meal_time) > philos->time_to_die)
			{
				philos->one_death = true;
				printf("last meal time %lld:\n",(current_time() - philos->threads[i].last_meal_time));
				print_message("dead", &philos->threads[i], 1);
				break ;
			}
			i++;
		}
		i = 0;
	}
	return (0);
}
