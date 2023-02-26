/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:07:30 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/26 22:13:37 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_data *phi)
{
	t_time_lim	*tcond;
	t_forkinfo	*fork;

	tcond = phi->timelimit;
	fork = phi->fork;

	phi->timedie = phi->timestart + tcond->die;
	while(get_utime() < phi->timestart)
		;
	philo_wait(phi);
	while ((phi->no_ate != phi->timelimit->no_eat))
	{
		if (pick_fork_eat(phi, tcond, fork))
			break;
		if (philo_sleep_think(phi, tcond))
			break ;
	}
	return (NULL);
}

int	pick_fork_eat(t_data *phi, t_time_lim *tcond, t_forkinfo *fork)
{
	if (phi->tag == 1 || phi->tag == 2)
		return (pickfork_eat_normal(phi, tcond, fork));
	else if (phi->tag == 3)
		return (pickfork_eat_lastodd(phi, tcond, fork));
	return (1);
}

// pick right fork first
int	pickfork_eat_normal(t_data *phi, t_time_lim *tcond, t_forkinfo *fork)
{
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	printf("BUG-0000  %d\n", phi->id);
	printing(phi, "has taken a fork", 0);
	phi->left_stat = 1;
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	printing(phi, "has taken a fork", 0);
	phi->right_stat = 1;
	phi->timedie += tcond->die;
	if (cal_upickeat(phi, tcond, fork))
		return (1);
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	phi->right_stat = 0;
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	phi->left_stat = 0;
	phi->no_ate++;
	return (0);
}

int	philo_sleep_think(t_data *phi, t_time_lim *tcond)
{
	printing(phi, "is sleeping", 0);
	cal_usleepthink(phi, tcond, tcond->slp);
	printing(phi, "is thinking", 0);
	return (0);
}

// just pick L fork first
int	pickfork_eat_lastodd(t_data *phi, t_time_lim *tcond, t_forkinfo *fork)
{
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	printf("BUG-1000  %d\n", phi->id);
	printing(phi, "has taken a fork", 0);
	phi->right_stat = 1;
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	printing(phi, "has taken a fork", 0);
	phi->left_stat = 1;
	phi->timedie += tcond->die;
	if (cal_upickeat(phi, tcond, fork))
		return (1);
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	phi->left_stat = 0;
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	phi->right_stat = 0;
	phi->no_ate++;
	return (0);
}
