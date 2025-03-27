/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 22:12:50 by mabdelha          #+#    #+#             */
/*   Updated: 2025-03-24 22:12:50 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data t_data;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	long			last_meal_time;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	long			start_time;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	t_philosopher	*philosophers;
}					t_data;

t_data    *init_tabl(int argc, char **argv);
void    *ft_routine(void *arg);
int	ft_atoi(const char *str);
long    ft_time();
void    ft_print(t_philosopher *philo, char *str);
void    ft_check(t_data *data);

#endif