/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/10 12:50:26 by mkhlouf          ###   ########.fr       */
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

void	take_right_fork(t_thread *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, 0);
}

void	take_left_fork(t_thread *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_message("has taken a fork", philo, 0);
}

void	ft_usleep(uintmax_t usec, uintmax_t from_time, t_philo *philos)
{
	uintmax_t	start;

	start = from_time;
	while (true)
	{
		pthread_mutex_lock(&philos->general_lock);
		if (philos->one_death)
		{
			pthread_mutex_unlock(&philos->general_lock);
			return ;
		}
		if (current_time() - start < usec && !philos->one_death)
		{
			pthread_mutex_unlock(&philos->general_lock);
			usleep(100);
		}
		else
		{
			pthread_mutex_unlock(&philos->general_lock);
			return ;
		}
	}
}
