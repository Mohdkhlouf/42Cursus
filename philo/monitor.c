/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:33 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/23 00:41:20 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *msg, t_thread *philo, int skip)
{
	if (!philo->philos->one_death || skip == 1)
	{
		pthread_mutex_lock(&philo->philos->print_lock);
		printf("%lld %d %s\n", (current_time() - philo->start_time),
			philo->philo_num, msg);
		pthread_mutex_unlock(&philo->philos->print_lock);
	}
}


void *philos_monitor(void *arg)
{
    t_philo *philos;
    int i;
	
    i = 0;
    philos = (t_philo *)arg;
    while (1)
    {
        pthread_mutex_lock(&philos->print_lock);  // Lock the print mutex

        // Check if any philosopher has died
        i = 0;
        while ( i < philos->philos_number)
        {
            
            if ((current_time() - philos->threads[i].last_meal_time) > philos->time_to_die)
            {
                philos->one_death = true;
            //     // print_message("died", &philos->threads[i], 1);  // Print death message

            //     // Update philosopher status to DEAD (important if you have further checks)
                philos->threads[i].next_status = DEAD;  // Set the philosopher's status to DEAD

            //     // Optionally, print more information about the philosopher’s death
                pthread_mutex_unlock(&philos->print_lock);  // Unlock after the check
                return (0);  // Exit the monitor thread, which will stop all philosophers
            }
			if ((philos->threads[i].eating_conter >= philos->eating_rounds) && !philos->all_eat)
            {
                philos->all_eating_counter++;
                if(philos->all_eating_counter == philos->philos_number)
				    philos->all_eat = true;
            }
                
			i++;
        }
		pthread_mutex_unlock(&philos->print_lock);  // Unlock the mutex after checking all philosophers
        usleep(1000);  // Sleep for a while before checking again (to reduce CPU load)
    }

    return (0);
}


// void	*philos_monitor(void *arg)
// {
// 	t_philo	*philos;
// 	int		i;

// 	i = 0;
// 	philos = (t_philo *)arg;
// 	while (1 && !philos->one_death)
// 	{
// 		pthread_mutex_lock(&philos->print_lock);
// 		while (i < philos->philos_number)
// 		{
			
// 			if ((current_time()
// 					- philos->threads[i].last_meal_time) > philos->time_to_die)
// 			{
// 				philos->one_death = true;
// 				// philos->threads[i].next_status = DEAD;
// 				printf("%d is last meal time %lld:\n",
// 					philos->threads[i].philo_num, (current_time()
// 						- philos->threads[i].last_meal_time));
// 				print_message("dead", &philos->threads[i], 1);
// 				pthread_mutex_unlock(&philos->print_lock);
// 				break ;
// 			}
// 			i++;
			
// 		}
// 		pthread_mutex_unlock(&philos->print_lock);
// 		i = 0;
// 	}
// 	return (0);
// }
