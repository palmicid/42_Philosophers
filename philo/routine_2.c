/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:04 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/03 05:57:26 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cal_upickeat(t_data *phi, t_time_lim *tcond, t_forkinfo *fork)
{
	my_usleep(tcond->eat);
	return (0);
}

void	philo_wait(t_data *phi, t_forkinfo *fork)
{
	if (phi->tag == 2)
		my_usleep(phi->timelimit->eat * 1);
	else if (phi->tag == 3)
		my_usleep(phi->timelimit->eat * 1);
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


