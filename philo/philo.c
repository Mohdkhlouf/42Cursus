/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/13 15:52:53 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(char **argv, t_philo *philo)
{
	philo->philos_number = ft_atoi(argv[1]);
	philo->forks_number = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_die = ft_atoi(argv[3]);
	philo->time_to_die = ft_atoi(argv[4]);
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
	if (argc == 5)
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

int	main(int argc, char **argv)
{
	t_philo philo;
	struct timeval current_time;
	
	if (check_arguments(argc, argv, &philo))
	{	
		gettimeofday(&current_time, NULL);
		philo.current_time = current_time.tv_sec;
	}
	else
	{
		printf("Error, check your arguments");
	}
	return (0);
}