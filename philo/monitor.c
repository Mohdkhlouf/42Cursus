/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/27 12:12:41 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*i hhave deleted the monitor, and now i am using the print instead, so when i
print i test and do the monitor job,
	these function dont return any thing on success,
and handeld in the routine file*/
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
				// return (1);
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
			// philos->threads[i].next_status = DEAD;
			// pthread_mutex_unlock(&philos->general_lock);
			// print_message("is dead", &philos->threads[i], 1);
			// pthread_mutex_lock(&philos->print_lock);

			printf("%ld %d %s\n", (current_time()
					- philos->threads[i].start_time),
				philos->threads[i].philo_num, "is dead");
			pthread_mutex_unlock(&philos->general_lock);
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
	if (!philo->philos->one_death || skip == 1)
	{
		pthread_mutex_lock(&philo->philos->print_lock);
		printf("%ld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
		pthread_mutex_unlock(&philo->philos->print_lock);
	}
}

// void	*philos_monitor(void *arg)
// {
// 	t_philo	*philos;

// 	philos = (t_philo *)arg;
// 	while (1 && !philos->one_death)
// 	{
// 		check_death(philos);
// 		usleep(1000);
// 	}
// 	return (0);
// }
