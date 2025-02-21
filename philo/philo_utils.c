/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:48 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/21 17:12:37 by mkhlouf          ###   ########.fr       */
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
	philo->one_death = false;
	philo->all_eat = false;
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
				i++;
			else
			{
				printf("arguments are not digits \n");
				return (0);
			}
		}
		philo_init(argv, philo);
	}
	return (1);
}
int ft_atoi(const char *str)
{
    int sign = 1;
    int i = 0;
    int num = 0;
    int max_int = 2147483647; // Max int value for checking overflow

    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
        || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (num > (max_int - (str[i] - '0')) / 10)
        {
            // Overflow, handle it
            return (sign == 1 ? max_int : -max_int - 1);
        }
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}


long long	current_time()
{
	struct timeval	tv;
	long long		milliseconds;

	milliseconds = 0;
	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec * (long long)1000) + tv.tv_usec / 1000;
	return (milliseconds);
}


