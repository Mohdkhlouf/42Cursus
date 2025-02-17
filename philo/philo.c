/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/17 13:17:05 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_thread *philo)
{
	philo->is_thinking = 1;
	print_message("is thinking", philo);
	philo->is_thinking = 0;
}
void	print_message(char *msg, t_thread *philo)
{
	pthread_mutex_t	print_lock;

	pthread_mutex_init(&print_lock, NULL);
	pthread_mutex_lock(&print_lock);
	printf("%lld %d %s\n", (current_time() - philo->start_time),
		philo->philo_num, msg);
	pthread_mutex_unlock(&print_lock);
	pthread_mutex_destroy(&print_lock);
}

void	philo_sleep(t_thread *philo)
{
	philo->is_sleeping = 1;
	print_message("is sleeping", philo);
	usleep(philo->philos->time_to_sleep * 1000);
	philo->is_sleeping = 0;
}

void	philo_eat(t_thread *philo)
{
	philo->last_meal_time = current_time() - philo->start_time;
	print_message("is eating", philo);
	usleep(philo->philos->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo_sleep(philo);
}
void	dead_lock_avoid(t_thread *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		if (pthread_mutex_lock(philo->right_fork) == 0 && pthread_mutex_lock(&philo->left_fork) == 0)
		{
			print_message("has taken the right fork", philo);
			print_message("has taken the left fork", philo);
			philo_eat(philo);
			philo_think(philo);			
		}
	}
	else
	{
		if (philo->right_fork)
		{
			if (pthread_mutex_lock(&philo->left_fork) == 0 && pthread_mutex_lock(philo->right_fork) == 0)
			{
				print_message("has taken the left fork", philo);
				print_message("has taken the right fork", philo);
				philo_eat(philo);
				philo_think(philo);
			}
		}
	}
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;
	int			i;

	i = 0;
	philo = (t_thread *)arg;
	philo->start_time = current_time() - philo->start_time;
	print_message("is thinking", philo);
	while (i < 5)
	{
		dead_lock_avoid(philo);
		if (philo->last_meal_time == philo->philos->time_to_die)
		{
			print_message("has died", philo);
			break ;
		}
		i++;
	}
	return (0);
}
void	philo_create(t_philo *philo)
{
	int	i;

	i = 0;
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
}
void	philo_var_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos_number)
	{
		pthread_mutex_init(&philo->threads[i].left_fork, NULL);
		philo->threads[i].philo_num = i + 1;
		philo->threads[i].philos = philo;
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
void	*philos_monitor(void *arg)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)arg;
	while (1)
	{
		while (i < philos->philos_number)
		{
			if (philos->threads[i].last_meal_time == philos->time_to_die)
			{
				print_message("has died", &philos->threads[i]);
				exit(-1);
			}
			i++;
		}
		i = 0;
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