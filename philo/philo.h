/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:47 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/23 00:35:27 by mkhlouf          ###   ########.fr       */
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
	long long			last_meal_time;
	int					next_status;
	int					eating_conter;
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
	int					all_eating_counter;
	bool				one_death;
	bool				all_eat;
	pthread_mutex_t		print_lock;

	t_thread			*threads;

}						t_philo;

int						ft_atoi(const char *str);
void					philo_init(char **argv, t_philo *philo, int argc);
int						check_ints(char *str);
int						check_arguments(int argc, char **argv, t_philo *philo);
long long				current_time(void);
void					print_message(char *msg, t_thread *philo, int skip);
int						dead_lock_avoid(t_thread *philo);
void					*philo_routine(void *arg);
void					philo_create(t_philo *philo);
void					philo_var_init(t_philo *philo);
void					create_philos(t_philo *philo);
void					*philos_monitor(void *arg);
void					drop_left_fork(t_thread *philo);
void					drop_right_fork(t_thread *philo);
int						take_right_fork(t_thread *philo);
int						take_left_fork(t_thread *philo);
void					philo_think(t_thread *philo);
void					philo_sleep(t_thread *philo);
void					philo_eat(t_thread *philo);
int						dead_lock_avoid(t_thread *philo);
void					philosopher_status_set(t_thread *philo, int i);

#endif