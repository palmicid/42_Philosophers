/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:07:30 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/18 17:44:25 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_fork(t_data *phi)
{
	pthread_mutex_lock(&phi->fork->fmutex[phi->num_r]);
	printf("%lu %d is taken a fork\n", get_time() - phi->timestart, phi->id);
	pthread_mutex_unlock(&phi->fork->fmutex[phi->num_r]);
}



void	*routine(t_data *phi)
{
	unsigned long	test;
	unsigned long	present;
	
	present = get_time();
	while(get_time() < phi->timestart)
		usleep(50);
	printf("test %d | %lu\n", phi->id, present);
	// plus die time
	while ((phi->no_ate != phi->timelimit->no_eat))
	{
		phi->no_ate++;
		// pickup fork + thinking
		// eat --> plus die time
		// sleep
		if (phi->id == 4)
			phi->fork->die_stat = 0;
		test = get_time() - phi->timestart;
		printf("%lu %d  | %lu | %lu\n", test, phi->id, get_time(), phi->timestart);
	}
	return (phi);
}
