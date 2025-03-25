/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-25 00:16:13 by mabdelha          #+#    #+#             */
/*   Updated: 2025-03-25 00:16:13 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    ft_time()
{
    struct timeval  tv;
    
}

void    init_fork(t_data *data)
{
    int i;

    i = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
    if (!data->forks)
        return;
    while (i < data->philo_count)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_mutex, NULL);
}

void    init_philo(t_data *data)
{
    int i;
    t_philosopher   *philo;

    i = 0;
    while (i < data->philo_count)
    {
        philo->id = i + 1;
        philo->        
    }
    
}
void    init_tabl(int argc, char **argv)
{
    t_data  *data;

    data->philo_count = argv[1];
    data->time_to_die = argv[2];
    data->time_to_eat = argv[3];
    data->time_to_sleep = argv[4];
    if (argc == 6)
        data->eat_count = argv[5];
    else
        data->eat_count = argv[6];
}