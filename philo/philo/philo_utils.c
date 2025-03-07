/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:48 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/07 16:43:29 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(char **argv, t_philo *philo, int argc)
{
	philo->philos_number = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->eating_rounds = 0;
	if (argc == 6)
		philo->eating_rounds = ft_atoi(argv[5]);
	else if (argc == 5)
		philo->eating_rounds = 10000;
	philo->one_death = false;
	philo->all_eat = false;
	philo->all_eating_counter = 0;
	philo->all_started = 0;
	philo->counter = 0;
}

int	check_ints(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_arguments(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 1;
	if (argc == 6 || argc == 5)
	{
		while (i < argc)
		{
			if (check_ints(argv[i]))
				i++;
			else
				return (0);
		}
		philo_init(argv, philo, argc);
	}
	else
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if ((num > INT_MAX) || (num < INT_MIN))
		return (-1);
	return (num * sign);
}

uintmax_t	current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uintmax_t)1000) + (tv.tv_usec / 1000));
}
