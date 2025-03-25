/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhaqmarouan <abdelhaqmarouan@student.42.fr>  #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 12:30:03 by abdelhaqmarouan   #+#    #+#             */
/*   Updated: 2025-03-24 12:30:03 by abdelhaqmarouan  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosopher.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	invalid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (invalid_args(argc, argv) == 1)
	{
		printf("Error: invalid caratir in arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		return (1);
	i = 1;
	while (i < argc)
	{
		printf("%d\n", ft_atoi(argv[i]));
		i++;
	}
	return (0);
}
