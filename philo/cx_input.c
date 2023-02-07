/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:24:18 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/02 22:15:43 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cx_number(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	atoi_philo(char *str)
{
	int	i;
	int num;

	num = 0;
	i = 0;
	while (str[i])
	{
		num *= 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num);
}

int	cx_data(int ac, char **av, t_time_lim *timebox)
{
	// cx_isnum
	if (!cx_number(av))
		return (0);
	// short atoi
	// add to struct
	timebox->no_ph = atoi_philo(av[1]);
	timebox->die =  atoi_philo(av[2]);
	timebox->eat = atoi_philo(av[3]);
	timebox->slp = atoi_philo(av[4]);
	if (ac == 6)
		timebox->no_eat = atoi_philo(av[5]);
	else
		timebox->no_eat = -1;	
	return (1);
}
