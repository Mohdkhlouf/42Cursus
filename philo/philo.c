/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/20 01:16:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_create(t_philo *philo)
{
	int			i;
	long long	temp;

	i = 0;
	temp = 0;
	pthread_mutex_lock(&philo->print_lock);
	while (i < philo->philos_number)
	{
		philosopher_status_set(philo->threads, i);
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine,
				(void *)&philo->threads[i]) != 0)
		{
			perror("Error: ");
			free(philo->threads);
			return ;
		}
		i++;
	}
	i = 0;
	temp = current_time();
	while (i < philo->philos_number)
	{
		philo->threads[i].start_time = temp;
		philo->threads[i].last_meal_time = temp;
		i++;
	}
	pthread_mutex_unlock(&philo->print_lock);
}
void	philo_var_init(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->print_lock, NULL);
	while (i < philo->philos_number)
	{
		pthread_mutex_init(&philo->threads[i].left_fork, NULL);
		philo->threads[i].philo_num = i + 1;
		philo->threads[i].philos = philo;
		philo->threads[i].start_time = 0;
		philo->threads[i].last_meal_time = 0;
		if (i == philo->philos_number - 1)
			philo->threads[i].right_fork = &philo->threads[0].left_fork;
		else
			philo->threads[i].right_fork = &philo->threads[i + 1].left_fork;
		i++;
	}
	if (philo->philos_number == 1)
	{
		// pthread_mutex_init(philo->threads[0].right_fork, NULL);
		philo->threads[0].right_fork = NULL;
	}
}

void	create_philos(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	philo->threads = malloc(sizeof(t_thread) * philo->philos_number);
	if (!philo->threads)
		return ;
	philo_var_init(philo);
	philo_create(philo);
	
	if ((pthread_create(&monitor, NULL, philos_monitor, (void *)philo)) != 0)
	{
		perror("Error: ");
		free(philo->threads);
		return ;
	}

	i = 0;
	while (i < philo->philos_number)
	{
		pthread_join(philo->threads[i].thread_id, NULL);
		i++;
	}
	// pthread_join(monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_philo philo;

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