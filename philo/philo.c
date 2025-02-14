/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/14 16:31:18 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->current_time, NULL);
	printf("philo Current time: %ld\n", philo->current_time.tv_sec);
	sleep(3);
	return (0);
}

void set_started_time(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	philo->started_time = philo->current_time.tv_sec;
	printf("startd the simulaton at: %ld\n", philo->started_time);
}
void	create_philos(t_philo *philo)
{
	int			i;

	i = 0;
	philo->threads = malloc(sizeof(t_thread) * philo->philos_number);
	if(!philo->threads)
		{
			return;
		}
	set_started_time(philo);
	while (i < philo->philos_number)
	{
		philo->threads[i].thread_num = i;
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine, (void *)philo) != 0)
		{
			perror("Error: ");
			free(philo->threads);
			break;
		}
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