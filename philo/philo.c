/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:43:31 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/03 00:50:52 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




void process(t_time_lim *timebox)
{
	pthread_t	*philo;
	int			num;
	t_data		*phiiden;

	num = 0;
	philo = (pthread_t *)malloc(sizeof(pthread_t) * timebox->no_ph);
	if (!philo)
		return ;
	phiiden = (t_data *)malloc(sizeof(t_data) * timebox->no_ph);
	while (num < timebox->no_ph)
	{
		phiiden[num].id = num + 1;
		pthread_create(&philo[num], NULL, &routine, &phiiden[num]);
		num++;
	}
	num = 0;
	while (num < timebox->no_ph)
	{
		pthread_join(philo[num], NULL);
		num++;
	}
}

int	main(int ac, char **av)
{
	t_time_lim	*timebox;

	timebox = (t_time_lim *)malloc(sizeof(t_time_lim));
	if (!timebox)
		return (0);
	// cx_inout and init to struct
	if (ac == 5 || ac == 6)
	{
		if (cx_data(ac, av, timebox))
		{
			// process
			process(timebox);
		}
	}
	// clear everything
	free(timebox);
	return (0);
}
