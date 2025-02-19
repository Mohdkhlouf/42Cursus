/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/19 17:18:42 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_monitor(void *arg)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)arg;

	while (1 && !philos->one_death)
	{
		pthread_mutex_lock(&philos->print_lock);
		while (i < philos->philos_number)
		{
			if ((current_time() - philos->threads[i].last_meal_time) > philos->time_to_die)
			{
				philos->one_death = true;
				print_message("dead", &philos->threads[i]);
				break ;
			}
			i++;
		}
		pthread_mutex_unlock(&philos->print_lock);
		i = 0;
	}
	return (0);
}

void	print_message(char *msg, t_thread *philo)
{
	// if some body has died, then dont print.
	
	if (!philo->philos->one_death)
	{
		pthread_mutex_lock(&philo->philos->print_lock);
		printf("%lld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
		pthread_mutex_unlock(&philo->philos->print_lock);
	}
	
}

void	philo_think(t_thread *philo)
{
	long long	time;

	time = 0;
	print_message("is thinking", philo);
	// usleep(philo->philos->time_to_eat * 1000);
	pthread_mutex_lock(&philo->philos->print_lock);
	if (philo->philos->one_death == true)
	{
		philo->next_status = DEAD;
	}
	philo->next_status = EATING;
	pthread_mutex_unlock(&philo->philos->print_lock);
}

void	philo_sleep(t_thread *philo)
{
	print_message("is sleeping", philo);
	usleep(philo->philos->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->philos->print_lock);
	philo->next_status = THINKING;
	pthread_mutex_unlock(&philo->philos->print_lock);
}

void	philo_eat(t_thread *philo)
{
	if (philo->philos->time_to_die + philo->last_meal_time > current_time()
		+ philo->philos->time_to_eat)
	{
		usleep(2000);
	}
	dead_lock_avoid(philo);
	philo->last_meal_time = current_time();
	print_message("is eating", philo);
	usleep(philo->philos->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->next_status = SLEEPING;
}
void	drop_left_fork(t_thread *philo)
{
	pthread_mutex_unlock(&philo->left_fork);
}

void	drop_right_fork(t_thread *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

int	take_right_fork(t_thread *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	return (0);
}

int	take_left_fork(t_thread *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_message("has taken a fork", philo);
	return (0);
}

int	dead_lock_avoid(t_thread *philo)
{
	// ate last + time to die is larger that time now + time to eat,
	// so wait 2 ms as example;
	if (philo->philos->one_death == false)
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
			return (0);
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
			return (0);
		}
	}
	else
	{
		printf("Exiting\n");
		exit(1);
	}
	return (0);
}

void	philosopher_status_set(t_thread *philo, int i)
{
	if ((i % 2) == 0)
	{
		philo[i].next_status = THINKING;
	}
	else
	{
		philo[i].next_status = EATING;
	}
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;
	int			i;

	i = 0;
	philo = (t_thread *)arg;
	pthread_mutex_lock(&philo->philos->print_lock);
	pthread_mutex_unlock(&philo->philos->print_lock);
	while (i < 10)
	{
		// if (philo->next_status == DEAD || philo->philos->one_death == true)
		// {
		// 	print_message("died", philo);
		// 	exit(1);
		// }
		if (philo->next_status == THINKING)
			philo_think(philo);
		if (philo->next_status == EATING)
			philo_eat(philo);
		if (philo->next_status == SLEEPING)
			philo_sleep(philo);
		i++;
	}
	return (0);
}
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