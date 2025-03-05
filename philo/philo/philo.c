/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/05 13:55:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_create(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (philo->eating_rounds == 0)
		return ;
	while (i < philo->philos_number)
	{
		if (pthread_create(&philo->threads[i].thread_id, NULL, philo_routine,
				(void *)&philo->threads[i]) != 0)
		{
			perror("Error: ");
			free(philo->threads);
			return ;
		}
		philo->counter++;
		i++;
	}
	philo_init_after(philo);
	philo->all_started = 1;
	pthread_create(&monitor, NULL, monitor_checker, (void *)philo);
	pthread_join(monitor, NULL);
}

void	phiol_vat_init2(t_philo *philo, int i)
{
	philo->threads[i].philo_num = i + 1;
	philo->threads[i].philos = philo;
	philo->threads[i].start_time = 0;
	philo->threads[i].last_meal_time = 0;
	philo->threads[i].eating_conter = 0;
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
		phiol_vat_init2(philo, i);
		if (i % 2 == 0)
			philo->threads[i].next_status = EATING;
		else
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

// test when eating rounds is 0
// when sleeping and eating time so long..
// when thhread creating faild...
