/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher .h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhaqmarouan <abdelhaqmarouan@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 12:21:49 by abdelhaqmarouan   #+#    #+#             */
/*   Updated: 2025-03-24 12:21:49 by abdelhaqmarouan  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H


typedef struct s_philosopher {
    int id;
    pthread_t thread;
    int meals_eaten;
    long last_meal_time;
    struct s_data *data;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_philosopher;

typedef struct s_data
{
    int				philo_count;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				eat_count;
    long    		start_time;
    pthread_mutex_t	*forks;
    pthread_mutex_t	print_mutex;
}	t_data;


# include <pthread.h>
# include <stlib.h>
# include <unistd.h>
# include <sys/tymes.h>

#endif