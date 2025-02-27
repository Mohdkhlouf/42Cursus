/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/27 16:45:45 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
	usleep(20);
	print_message("is thinking", philo, 0);
	pthread_mutex_lock(&philo->philos->general_lock);
	if (philo->philos->one_death == true)
		philo->next_status = DEAD;
	else
		philo->next_status = EATING;
	pthread_mutex_unlock(&philo->philos->general_lock);
}

void	philo_sleep(t_thread *philo)
{
	print_message("is sleeping", philo, 0);
	pthread_mutex_lock(&philo->philos->general_lock);
	if (philo->philos->one_death == true)
	{
		philo->next_status = DEAD;
		pthread_mutex_unlock(&philo->philos->general_lock);
	}
	else
	{
		if (philo->philos->all_eat)
			philo->next_status = ENOUGH_ROUNDS;
		else
			philo->next_status = THINKING;
		pthread_mutex_unlock(&philo->philos->general_lock);
	}
	usleep(philo->philos->time_to_sleep * 1000);
}

void	philo_eat(t_thread *philo)
{
	if (philo->philos->time_to_die + philo->last_meal_time > current_time()
		+ philo->philos->time_to_eat)
	{
		usleep(200);
	}
	dead_lock_avoid(philo);
	{
		print_message("is eating", philo, 0);
		pthread_mutex_lock(&philo->philos->general_lock);
		philo->last_meal_time = current_time();
		pthread_mutex_unlock(&philo->philos->general_lock);
		usleep(philo->philos->time_to_eat * 1000);
		philo->eating_conter++;
		drop_left_fork(philo);
		drop_right_fork(philo);
		pthread_mutex_lock(&philo->philos->general_lock);
		philo->next_status = SLEEPING;
		pthread_mutex_unlock(&philo->philos->general_lock);
	}
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
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *)arg;
	pthread_mutex_lock(&philo->philos->general_lock);
	pthread_mutex_unlock(&philo->philos->general_lock);
	while (true && !philo->philos->one_death)
	{
		if (philo->next_status == DEAD)
		{
			break ;
		}
		else if (philo->next_status == ENOUGH_ROUNDS)
			break ;
		else if (philo->next_status == THINKING)
			philo_think(philo);
		else if (philo->next_status == EATING)
			philo_eat(philo);
		else if (philo->next_status == SLEEPING)
			philo_sleep(philo);
		else
			philo->next_status = THINKING;
	}
	return (NULL);
}
