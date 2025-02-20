/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/21 01:40:37 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
	print_message("is thinking", philo, 0);
	if (philo->philos->one_death == true)
		philo->next_status = DEAD;
	else
		philo->next_status = EATING;
}

void	philo_sleep(t_thread *philo)
{
	print_message("is sleeping", philo, 0);
	usleep(philo->philos->time_to_sleep * 1000);
	philo->next_status = THINKING;
}

void	philo_eat(t_thread *philo)
{
	if (philo->philos->time_to_die + philo->last_meal_time > current_time()
		+ philo->philos->time_to_eat)
	{
		usleep(2000);
	}
	dead_lock_avoid(philo);
	philo->last_meal_time = current_time();
	print_message("is eating", philo, 0);
	usleep(philo->philos->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->next_status = SLEEPING;
}

int	dead_lock_avoid(t_thread *philo)
{
		if (philo->philo_num % 2 == 0)
		{
			if (take_right_fork(philo) != 0)
				return (1);
			if (take_left_fork(philo) != 0)
			{
				drop_right_fork(philo);
				return (1);
			}
			return (0);
		}
		else
		{
			if (take_left_fork(philo) != 0)
				return (1);
			if (take_right_fork(philo) != 0)
			{
				drop_left_fork(philo);
				return (1);
			}
			return (0);
		}

	return (0);
}

void	*philo_routine(void *arg)
{
	t_thread *philo;
	int i;

	i = 0;
	philo = (t_thread *)arg;
	pthread_mutex_lock(&philo->philos->print_lock);
	pthread_mutex_unlock(&philo->philos->print_lock);
	// while (i < 10 && !philo->philos->one_death)
	while (true)
	{
		// if (philo->next_status == DEAD || philo->philos->one_death == true)
		// {
		// 	print_message("died", philo);
		// 	exit(1);
		// }
		if (philo->next_status == THINKING)
			philo_think(philo);
		else if (philo->next_status == EATING)
			philo_eat(philo);
		else if (philo->next_status == SLEEPING)
			philo_sleep(philo);
		i++;
	}
	return (0);
}