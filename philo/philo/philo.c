/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/07 16:43:34 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_create(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < philo->philos_number)
	{
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine,
				(void *)&philo->threads[i]) != 0)
		{
			return (FAILURE);
		}
		philo->counter++;
		i++;
	}
	philo_init_after(philo);
	philo->all_started = 1;
	if (pthread_create(&monitor, NULL, monitor_checker, (void *)philo) != 0)
		return (FAILURE);
	pthread_join(monitor, NULL);
	return (SUCCESS);
}

void	philo_vat_init2(t_philo *philo, int i)
{
	philo->threads[i].philo_num = i + 1;
	philo->threads[i].philos = philo;
	philo->threads[i].start_time = 0;
	philo->threads[i].last_meal_time = 0;
	philo->threads[i].eating_conter = 0;
	if (i % 2 == 0)
		philo->threads[i].next_status = EATING;
	else
		philo->threads[i].next_status = THINKING;
}

int	philo_var_init(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&philo->print_lock, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&philo->general_lock, NULL) != 0)
		return (pthread_mutex_destroy(&philo->print_lock), FAILURE);
	while (i < philo->philos_number)
	{
		if (pthread_mutex_init(&philo->threads[i].left_fork, NULL) != 0)
		{
			cleanup_mutexes(philo, i);
			return (FAILURE);
		}
		philo_vat_init2(philo, i);
		if (i == philo->philos_number - 1 && i > 0)
			philo->threads[i].right_fork = &philo->threads[0].left_fork;
		else
			philo->threads[i].right_fork = &philo->threads[i + 1].left_fork;
		i++;
	}
	if (philo->philos_number == 1)
		philo->threads[0].right_fork = NULL;
	return (SUCCESS);
}

int	create_philos(t_philo *philo)
{
	philo->threads = malloc(sizeof(t_thread) * philo->philos_number);
	if (!philo->threads)
		return (FAILURE);
	if (!philo_var_init(philo))
		return (FAILURE);
	if (!philo_create(philo))
		return (exit_destroy(philo), FAILURE);
	exit_destroy(philo);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (check_arguments(argc, argv, &philo))
	{
		if (philo.eating_rounds == 0)
			return (FAILURE);
		if (!create_philos(&philo))
		{
			printf("Error, philos cannot be created");
			return (FAILURE);
		}
	}
	else
		printf("Error, check your arguments");
	return (0);
}
