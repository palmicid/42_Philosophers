/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:04 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/27 21:42:15 by pruangde         ###   ########.fr       */
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
	long	willdie;

	willdie = get_utime() + tcond->eat;
	if (phi->timedie < willdie)
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
	long	wakeup;

	wakeup = get_utime() + tslp;
	if (phi->timedie < wakeup)
	{
		printf("phidie = %ld\nphiwak = %ld\n", phi->timedie, wakeup);
		printf("sleep  = %ld\n", tcond->slp);
		my_usleep(phi->timedie - get_utime());
		printing(phi, "died", 1);
		return (1);
	}
	else
		my_usleep(tslp);
	return (0);
}

void	philo_wait(t_data *phi, t_forkinfo *fork)
{
	if (phi->tag == 2)
		my_usleep(phi->timelimit->eat * 1);
	else if (phi->tag == 3)
		my_usleep(phi->timelimit->eat * 1.5);
	else if (phi->num_l == phi->num_r)
	{
		pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
		printing(phi, "has taken a fork", 0);
		my_usleep(phi->timedie - get_utime());
		printing(phi, "died", 1);
	}
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


