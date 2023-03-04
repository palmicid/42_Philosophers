/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:04 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 15:11:33 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_wait(t_data *phi, t_finfo *fork)
{
	if (phi->tag == 2 || phi->tag == 3)
		usleep(phi->timelimit->eat);
}

// time /1000 for ms, killmode 1 = on 0 = off
int	printing(t_data *phi, char *str, int killmode)
{
	pthread_mutex_lock(&(phi->fork->writing));
	if (phi->fork->die_stat)
	{
		pthread_mutex_unlock(&(phi->fork->writing));
		return (1);
	}
	printf("%ld %d %s\n", (get_utime() - phi->timestart) / 1000, phi->id, str);
	if (killmode == 1)
		phi->fork->die_stat = killmode;
	pthread_mutex_unlock(&(phi->fork->writing));
	if (phi->fork->die_stat == 1)
		return (1);
	else
		return (0);
}

void	fork_down(t_data *phi, t_finfo *fork)
{
	pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
	pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
	pthread_mutex_unlock(&(fork->writing));
	pthread_mutex_unlock(&(fork->lock));
	return ;
}
