/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:38:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/05 13:56:02 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init_after(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos_number)
	{
		pthread_mutex_lock(&philo->general_lock);
		philo->threads[i].start_time = current_time();
		philo->threads[i].last_meal_time = current_time();
		pthread_mutex_unlock(&philo->general_lock);
		i++;
	}
}

void	dead_lock_avoid(t_thread *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
}

void	print_message(char *msg, t_thread *philo, int skip)
{
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
	while (i < philo->counter)
	{
		pthread_join(philo->threads[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < philo->counter)
	{
		pthread_mutex_destroy(&philo->threads[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->print_lock);
	pthread_mutex_destroy(&philo->general_lock);
	free(philo->threads);
}
