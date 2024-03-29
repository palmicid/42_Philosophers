/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:24:18 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 13:06:27 by pruangde         ###   ########.fr       */
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
	int	num;

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

int	cx_data(int ac, char **av, t_tlim *timebox)
{
	if (!cx_number(av))
		return (0);
	timebox->no_ph = atoi_philo(av[1]);
	timebox->die = atoi_philo(av[2]) * 1000;
	timebox->eat = atoi_philo(av[3]) * 1000;
	timebox->slp = atoi_philo(av[4]) * 1000;
	if (ac == 6)
		timebox->no_eat = atoi_philo(av[5]);
	else
		timebox->no_eat = -1;
	if (cx_zero(timebox))
		return (0);
	return (1);
}

int	cx_zero(t_tlim *timebox)
{
	if (!timebox->no_ph)
		return (1);
	if (!timebox->die)
		return (1);
	if (!timebox->eat)
		return (1);
	if (!timebox->slp)
		return (1);
	if (timebox->no_eat == 0)
		return (1);
	return (0);
}

void	error_msg(void)
{
	printf("How to input\n");
	printf("./philo NUM_PH DIE EAT SLEEP [NUM_EAT]\n\n");
	printf("NUM_PH  = Number of philosophers\n");
	printf("DIE     = Time to die\n");
	printf("EAT     = Time to eat\n");
	printf("SLEEP   = Time to sleep\n");
	printf("NUM_EAT = Number of time philosophers have to eat[OPTIONAL]\n");
}
