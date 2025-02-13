/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:47 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/13 15:42:54 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int philos_number;
	int forks_number;
	time_t time_to_die;
	time_t time_to_eat;
	time_t time_to_sleep;
	time_t current_time;
	
}	t_philo;

int	ft_atoi(const char *str);
#endif