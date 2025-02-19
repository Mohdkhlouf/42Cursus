/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/20 01:19:46 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	print_message("has taken a fork", philo, 0);
	return (0);
}

int	take_left_fork(t_thread *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_message("has taken a fork", philo, 0);
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
