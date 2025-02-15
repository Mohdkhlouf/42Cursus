/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/15 14:14:16 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_thread *philo)
{
	philo->is_sleeping = 1;
	printf("Philo %d is Sleeping \n", philo->thread_num);
	usleep(philo->philos->time_to_sleep * 1000);
	philo->is_sleeping = 0;
}

void	philo_eat(t_thread *philo)
{
	pthread_mutex_lock(&philo->fork);
	printf("Philo %d is Eatting \n", philo->thread_num);
	usleep(philo->philos->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;
	
	philo = (t_thread *)arg;
	printf("philo #%d:\n", philo->thread_num);
	gettimeofday(&philo->current_time, NULL);
	printf("philo Current time: %ld\n", philo->current_time.tv_sec);
	pthread_mutex_init(&philo->fork, NULL);
	philo_eat(philo);
	philo_sleep(philo);
	sleep(3);
	return (0);
}

void	create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->threads = malloc(sizeof(t_thread) * philo->philos_number);
	if (!philo->threads)
	{
		return ;
	}
	while (i < philo->philos_number)
	{
		philo->threads[i].thread_num = i;
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine,
				(void *)&philo->threads[i]) != 0)
		{
			perror("Error: ");
			free(philo->threads);
			break ;
		}
		i++;
	}
	i = 0;
	while (i < philo->philos_number)
	{
		pthread_join(philo->threads[i].thread_id, NULL);
		i++;
	}

}

int	main(int argc, char **argv)
{
	t_philo philo;

	if (check_arguments(argc, argv, &philo))
	{
		create_philos(&philo);
		printf("after creating phio");
	}
	else
	{
		printf("Error, check your arguments");
	}
	return (0);
}