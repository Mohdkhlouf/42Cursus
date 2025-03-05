/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:47 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/05 13:50:35 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdint.h>
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
	uintmax_t			start_time;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	uintmax_t			last_meal_time;
	atomic_int			next_status;
	atomic_int			eating_conter;
	t_philo				*philos;
}						t_thread;

typedef struct s_philo
{
	int					philos_number;
	uintmax_t			time_to_die;
	uintmax_t			time_to_eat;
	uintmax_t			time_to_sleep;
	atomic_int			eating_rounds;
	atomic_int			all_eating_counter;
	atomic_int			all_started;
	_Atomic bool 		one_death;
	_Atomic bool 		all_eat;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		general_lock;
	t_thread			*threads;
	int					counter;

}						t_philo;

int						ft_atoi(const char *str);
void					philo_init(char **argv, t_philo *philo, int argc);
int						check_ints(char *str);
int						check_arguments(int argc, char **argv, t_philo *philo);
uintmax_t				current_time(void);
void					print_message(char *msg, t_thread *philo, int skip);
void					*philo_routine(void *arg);
void					philo_create(t_philo *philo);
void					philo_var_init(t_philo *philo);
void					create_philos(t_philo *philo);
void					drop_left_fork(t_thread *philo);
void					drop_right_fork(t_thread *philo);
int						take_right_fork(t_thread *philo);
int						take_left_fork(t_thread *philo);
void					philo_think(t_thread *philo);
void					philo_sleep(t_thread *philo);
void					philo_eat(t_thread *philo);
void					dead_lock_avoid(t_thread *philo);
void					exit_destroy(t_philo *philo);
void					ft_usleep(uintmax_t usec, uintmax_t from_time,
							t_philo *philos);
void					*monitor_checker(void *arg);
void					philo_init_after(t_philo *philo);

#endif