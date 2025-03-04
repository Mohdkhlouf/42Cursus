/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/04 10:45:22 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
	uintmax_t	time;

	time = current_time();
	print_message("is thinking", philo, 0);
	if (philo->eating_conter == 0)
		ft_usleep(philo->philos->time_to_eat / 2, time, philo->philos);
	// pthread_mutex_lock(&philo->philos->general_lock);
	if (philo->philos->one_death == true)
		philo->next_status = DEAD;
	else
		philo->next_status = EATING;
	// pthread_mutex_unlock(&philo->philos->general_lock);
}

void	philo_sleep(t_thread *philo)
{
	uintmax_t	time;

	time = current_time();
	print_message("is sleeping", philo, 0);
	// pthread_mutex_lock(&philo->philos->general_lock);
	if (philo->philos->one_death == true)
		philo->next_status = DEAD;
	else if (philo->philos->all_eat)
		philo->next_status = ENOUGH_ROUNDS;
	else
		philo->next_status = THINKING;
	// pthread_mutex_unlock(&philo->philos->general_lock);
	ft_usleep(philo->philos->time_to_sleep, time, philo->philos);
}

void	philo_eat(t_thread *philo)
{
	// if (philo->philos->philos_number == 1)
	// 	return ;
	if (philo->philos->philos_number % 2 != 0 && philo->philos->time_to_die + philo->last_meal_time > current_time()
		+ philo->philos->time_to_eat)
	{
		usleep(200);
	}

	dead_lock_avoid(philo);
	print_message("is eating", philo, 0);
	// pthread_mutex_lock(&philo->philos->general_lock);
	philo->last_meal_time = current_time();
	// pthread_mutex_unlock(&philo->philos->general_lock);
	ft_usleep(philo->philos->time_to_eat, philo->last_meal_time, philo->philos);
	philo->eating_conter++;
	drop_left_fork(philo);
	drop_right_fork(philo);
	pthread_mutex_lock(&philo->philos->general_lock);
	philo->next_status = SLEEPING;
	pthread_mutex_unlock(&philo->philos->general_lock);
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

void	*philo_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *)arg;
	while (philo->philos->all_started == 0)
		usleep(10);
	if (philo->philos->philos_number == 1)
	{
		take_left_fork(philo);
		usleep(philo->philos->time_to_die * 1000);
		ft_usleep(philo->philos->time_to_die, current_time(), philo->philos);
		return (NULL);
	}
	philo->start_time = current_time();
	while (true && !philo->philos->all_eat)
	{
		if (philo->next_status == DEAD)
			break ;
		else if (philo->next_status == ENOUGH_ROUNDS)
			break ;
		else if (philo->next_status == THINKING)
			philo_think(philo);
		else if (philo->next_status == EATING)
			philo_eat(philo);
		else if (philo->next_status == SLEEPING)
			philo_sleep(philo);
		else
		{
			printf("no stsuts\n");
			break ;
		}
	}
	return (NULL);
}
