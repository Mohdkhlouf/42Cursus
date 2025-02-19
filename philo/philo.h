/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:47 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/19 13:09:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef enum a_status
{
	GET_FORK,
	EATING,
	THINKING,
	SLEEPING,
	DEAD,
	ENOUGH_ROUNDS,
}						t_status;

typedef struct s_thread
{
	pthread_t			thread_id;
	int					philo_num;
	long long			start_time;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	bool				is_eating;
	bool				is_sleeping;
	bool				is_thinking;
	long long			last_meal_time;
	int			next_status;
	t_philo				*philos;
	// _Atomic int			has_died;
}						t_thread;

typedef struct s_philo
{
	int					philos_number;
	int					forks_number;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					eating_rounds;
	bool				one_death;
	pthread_mutex_t		print_lock;

	t_thread			*threads;

}						t_philo;

int						ft_atoi(const char *str);
void					philo_init(char **argv, t_philo *philo);
int						check_ints(char *str);
int						check_arguments(int argc, char **argv, t_philo *philo);
long long				current_time(void);
void					print_message(char *msg, t_thread *philo);
int						dead_lock_avoid(t_thread *philo);

#endif