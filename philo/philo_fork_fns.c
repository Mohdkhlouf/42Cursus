/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/02 23:11:29 by mkhlouf          ###   ########.fr       */
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

void	ft_usleep(uintmax_t usec, t_philo *philos )
{
	uintmax_t	start;

	start = current_time();
	while (current_time() - start < usec)
	{
		check_death(philos);
		usleep(100);
	}	
}
