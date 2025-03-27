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

long    ft_time()
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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
    
    data->philosophers = malloc(sizeof(t_philosopher) * data->philo_count);
    if (!data->philosophers)
        return;
    i = 0;
    while (i < data->philo_count)
    {
        data->philosophers[i].id = i + 1;
        data->philosophers[i].meals_eaten = 0;
        data->philosophers[i].last_meal_time = ft_time();
        data->philosophers[i].data = data;
        data->philosophers[i].left_fork = &data->forks[i];
        if (i == data->philo_count - 1)
            data->philosophers[i].right_fork = &data->forks[0];
        else
            data->philosophers[i].right_fork = &data->forks[i + 1];
        pthread_create(&data->philosophers[i].thread, NULL, ft_routine, &data->philosophers[i]);
        usleep(100);
        i++;
    }
}
t_data    *init_tabl(int argc, char **argv)
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->philo_count = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->eat_count = ft_atoi(argv[5]);
    else
        data->eat_count = -1;
    data->dead = 0;
    pthread_mutex_init(&data->meal_mutex, NULL);
    init_fork(data);
    init_philo(data);
    if (!data->forks || !data->philosophers)
    {
        free(data->forks);
        free(data->philosophers);
        free(data);
        return (NULL);
    }
    data->start_time = ft_time();
    return (data);
}
