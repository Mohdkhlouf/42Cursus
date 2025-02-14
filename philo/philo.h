/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:47 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/14 16:31:24 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_thread
{
	pthread_t		thread_id;
	int				thread_num;

}					t_thread;

typedef struct s_philo
{
	int				philos_number;
	int				forks_number;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			started_time;
	int				eating_rounds;
	struct timeval	current_time;
	t_thread		*threads;

}					t_philo;

int					ft_atoi(const char *str);
void				philo_init(char **argv, t_philo *philo);
int					check_ints(char *str);
int					check_arguments(int argc, char **argv, t_philo *philo);

#endif