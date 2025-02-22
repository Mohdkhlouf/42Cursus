/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/22 20:43:43 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
	usleep(20);
	print_message("is thinking", philo, 0);
	// if (philo->philos->one_death == true)
	// 	philo->next_status = DEAD;
	// else
	philo->next_status = EATING;
}

void	philo_sleep(t_thread *philo)
{
	
	print_message("is sleeping", philo, 0);
	// if (philo->philos->one_death == true)
	// 	philo->next_status = DEAD;
	// else
	// {
		usleep(philo->philos->time_to_sleep * 1000);

		if(philo->philos->all_eat)
			philo->next_status = ENOUGH_ROUNDS;
		else
			philo->next_status = THINKING;
	// }
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
		philo->last_meal_time = current_time();
		usleep(philo->philos->time_to_eat * 1000);
		philo->eating_conter += 1;
		drop_left_fork(philo);
		drop_right_fork(philo);
		philo->next_status = SLEEPING;
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
	t_thread *philo;
	int i;

	i = 0;
	philo = (t_thread *)arg;
	pthread_mutex_lock(&philo->philos->print_lock);
	pthread_mutex_unlock(&philo->philos->print_lock);
	// while (i < 10 && !philo->philos->one_death)
	
	while (true)
	{
		if (philo->next_status == DEAD)
		{
			print_message("form routine died", philo, 1);
			break;
		}
		else if (philo->next_status == ENOUGH_ROUNDS)
			break;
		else if (philo->next_status == THINKING)
			philo_think(philo);
		else if (philo->next_status == EATING)
			philo_eat(philo);
		else if (philo->next_status == SLEEPING)
			philo_sleep(philo);
		else
		{
			printf("else, status is %d\n", philo->next_status);
			exit(-1);
		}
		i++;
	}
	usleep(200*1000);
	printf("Hi, philo %d , and eating %d times.\n",philo->philo_num, philo->eating_conter);
	exit(-1);
	return (NULL);
}