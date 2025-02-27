/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/27 16:45:41 by mkhlouf          ###   ########.fr       */
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
