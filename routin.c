/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhaqmarouan <abdelhaqmarouan@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-25 05:10:01 by abdelhaqmarouan   #+#    #+#             */
/*   Updated: 2025-03-25 05:10:01 by abdelhaqmarouan  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    ft_print(t_philosopher *philo, char *str)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    printf("%ld %d %s\n", ft_time() - philo->data->start_time, philo->id, str);
    pthread_mutex_unlock(&philo->data->print_mutex);
}

void    ft_eat(t_philosopher *philo)
{
    pthread_mutex_lock(philo->left_fork);
    if (philo->data->dead)
    {
        pthread_mutex_unlock(philo->left_fork);
        return;
    }
    ft_print(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    if (philo->data->dead)
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        return;
    }
    ft_print(philo, "has taken a fork");
    pthread_mutex_lock(&philo->data->meal_mutex);
    philo->last_meal_time = ft_time();
    pthread_mutex_unlock(&philo->data->meal_mutex);
    ft_print(philo, "is eating");
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_lock(&philo->data->meal_mutex);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->meal_mutex);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    ft_other(t_philosopher *philo)
{
    ft_print(philo, "is sleeping");
    usleep(philo->data->time_to_sleep * 1000);
    ft_print(philo, "is thinking");
}

void    *ft_routine(void *arg)
{
    t_philosopher   *philo;

    philo = (t_philosopher *)arg;
    while (1)
    {
        if (philo->data->dead)
            return (NULL);
        ft_eat(philo);
        if (philo->data->dead)
            return (NULL);
        ft_other(philo);
    }
    return (NULL);
}

