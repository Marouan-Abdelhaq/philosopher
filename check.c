/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhaqmarouan <abdelhaqmarouan@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-25 05:53:55 by abdelhaqmarouan   #+#    #+#             */
/*   Updated: 2025-03-25 05:53:55 by abdelhaqmarouan  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_check(t_data *data)
{
    int i;
    long time;
    while (!data->dead)
    {
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_lock(&data->meal_mutex);
            time = ft_time() - data->philosophers[i].last_meal_time;
            if (data->dead)
            {
                pthread_mutex_unlock(&data->meal_mutex);
                return;
            }
            pthread_mutex_unlock(&data->meal_mutex);
            if (time > data->time_to_die)
            {
                pthread_mutex_lock(&data->print_mutex);
                ft_print(&data->philosophers[i], "died");
                printf("Temps: %ld, Dernier repas: %ld, Temps pour mourir: %d\n", ft_time(), data->philosophers[i].last_meal_time, data->time_to_die);
                data->dead = 1;
                pthread_mutex_unlock(&data->print_mutex);
                return;
            }
            i++;
        }
        usleep(1000);
    }
}