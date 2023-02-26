/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:04 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/26 22:03:50 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cx_death(int stat)
{
	if (stat)
		return (1);
	return (0);
}

int	cal_upickeat(t_data *phi, t_time_lim *tcond, t_forkinfo *fork)
{
	if (phi->timedie < (get_utime() + tcond->die))
	{
		my_usleep(phi->timedie - get_utime());
		printing(phi, "died", 1);
		if (phi->right_stat == 1)
			pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
		if (phi->left_stat == 1)
			pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
		return (1);
	}
	else
		my_usleep(tcond->eat);
	return (0);
}

int	cal_usleepthink(t_data *phi, t_time_lim *tcond, long tslp)
{
	if (phi->timedie < (get_utime() + tslp))
	{
		my_usleep(phi->timedie - get_utime());
		printing(phi, "died", 1);
		return (1);
	}
	else
		my_usleep(tslp);
	return (0);
}

void	philo_wait(t_data *phi)
{
	if (phi->tag == 2)
		my_usleep(phi->timelimit->eat * 1);
	else if (phi->tag == 3)
		my_usleep(phi->timelimit->eat * 1.5);
}

// time /1000 for ms, killmode 1 = on 0 = off
void	printing(t_data *phi, char *str, int killmode)
{
	pthread_mutex_lock(&(phi->fork->writing));
	if (phi->fork->die_stat)
		return ;
	printf("%ld %d %s\n", (get_utime() - phi->timestart) / 1000, phi->id, str);
	phi->fork->die_stat = killmode;
	pthread_mutex_unlock(&(phi->fork->writing));
}


