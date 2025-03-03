/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/03 16:54:13 by mkhlouf          ###   ########.fr       */
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
		pthread_mutex_unlock(&philo->general_lock);
		pthread_mutex_lock(&philo->general_lock);
		philo->threads[i].last_meal_time = current_time();
		pthread_mutex_unlock(&philo->general_lock);

			if (i % 2 == 0)
			{
				philo->threads[i].next_status = EATING;
			}
			else
				philo->threads[i].next_status = THINKING;		

		i++;
	}
}

void	philo_create(t_philo *philo)
{
	int	i;

	i = 0;
		philo_init_after(philo);

	while (i < philo->philos_number)
	{
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine,
				(void *)&philo->threads[i]) != 0)
		{
			perror("Error: ");
			free(philo->threads);
			return ;
		}
		i++;
	}
	// philo_init_after(philo);
	philo->all_started = 1;

}

void	philo_var_init(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->print_lock, NULL);
	pthread_mutex_init(&philo->general_lock, NULL);
	while (i < philo->philos_number)
	{
		pthread_mutex_init(&philo->threads[i].left_fork, NULL);
		philo->threads[i].philo_num = i + 1;
		philo->threads[i].philos = philo;
		philo->threads[i].start_time = 0;
		philo->threads[i].last_meal_time = 0;
		philo->threads[i].eating_conter = 0;
		philo->threads[i].next_status = THINKING;
		if (i == philo->philos_number - 1 && i > 0)
			philo->threads[i].right_fork = &philo->threads[0].left_fork;
		else
			philo->threads[i].right_fork = &philo->threads[i + 1].left_fork;
		i++;
	}
	if (philo->philos_number == 1)
	{
		pthread_mutex_init(philo->threads[0].right_fork, NULL);
		// philo->threads[0].right_fork = NULL;
	}
}

void	create_philos(t_philo *philo)
{
	philo->threads = malloc(sizeof(t_thread) * philo->philos_number);
	if (!philo->threads)
		return ;
	philo_var_init(philo);
	philo_create(philo);
	exit_destroy(philo);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (check_arguments(argc, argv, &philo))
	{
		create_philos(&philo);
	}
	else
	{
		printf("Error, check your arguments");
	}
	return (0);
}
