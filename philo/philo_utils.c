/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:48 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/15 14:48:18 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_init(char **argv, t_philo *philo)
{
	philo->philos_number = ft_atoi(argv[1]);
	philo->forks_number = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->eating_rounds = ft_atoi(argv[5]);
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
	if (argc == 6)
	{
		while (i < argc)
		{
			if (check_ints(argv[i]))
				philo_init(argv, philo);
			else
			{
				printf("arguments are not digits \n");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	num;

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
	return (num * sign);
}

time_t current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec);
}
