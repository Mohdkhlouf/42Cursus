/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/09 14:11:41 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
		print_message("is thinking", philo, 0);

		if (philo->eating_conter == 0 && philo->philo_num % 2 != 0
			&& philo->philos->philos_number % 2 == 0)
		{
			ft_usleep(philo->philos->time_to_eat / 2, current_time(), philo->philos);
		}
		pthread_mutex_lock(&philo->philos->general_lock);
		philo->next_status = EATING;
		pthread_mutex_unlock(&philo->philos->general_lock);
	}
// }

void	philo_sleep(t_thread *philo)
{
	// uintmax_t	time;

	// time = current_time();
	print_message("is sleeping", philo, 0);
	usleep(philo->philos->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->philos->general_lock);
	if (philo->philos->one_death == true)
		philo->next_status = DEAD;
	else if (philo->eating_conter == philo->philos->eating_rounds)
		philo->next_status = ENOUGH_ROUNDS;
	else
		philo->next_status = THINKING;
	pthread_mutex_unlock(&philo->philos->general_lock);

	// ft_usleep(philo->philos->time_to_sleep, time, philo->philos);
}

void	philo_eat(t_thread *philo)
{
	uintmax_t	elapsed_time;

	uintmax_t	time;
	pthread_mutex_lock(&philo->philos->general_lock);
	elapsed_time = current_time() - philo->last_meal_time;
	if (philo->philos->philos_number % 2 != 0 && philo->philo_num % 2 != 0
		&& philo->philos->time_to_die
		- elapsed_time > philo->philos->time_to_eat)
	{
		pthread_mutex_unlock(&philo->philos->general_lock);
		usleep(philo->philos->time_to_eat / 2 * 1000);
	}
	else
		pthread_mutex_unlock(&philo->philos->general_lock);
	dead_lock_avoid(philo);
	time = current_time();
	print_message("is eating", philo, 0);
	pthread_mutex_lock(&philo->philos->general_lock);
	philo->last_meal_time = time;
	pthread_mutex_unlock(&philo->philos->general_lock);
	ft_usleep(philo->philos->time_to_eat, time, philo->philos);
	// usleep(philo->philos->time_to_eat * 1000);
	philo->eating_conter++;
	drop_left_fork(philo);
	drop_right_fork(philo);
	pthread_mutex_lock(&philo->philos->general_lock);
	philo->next_status = SLEEPING;
	pthread_mutex_unlock(&philo->philos->general_lock);
}

void	main_routine(t_thread *philo)
{
	while (true)
	{
		pthread_mutex_lock(&philo->philos->general_lock);
		if (philo->philos->one_death)
		{
			pthread_mutex_unlock(&philo->philos->general_lock);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->philos->general_lock);
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
	}
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *)arg;
	while (philo->philos->all_started == 0)
		usleep(50);
	if (philo->philos->philos_number == 1)
	{
		take_left_fork(philo);
		ft_usleep(philo->philos->time_to_die, current_time(), philo->philos);
		drop_left_fork(philo);
		return (NULL);
	}
	main_routine(philo);
	return (NULL);
}
