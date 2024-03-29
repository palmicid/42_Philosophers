/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:07:30 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 15:56:15 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_tlim	*tcond;
	t_finfo	*fork;
	t_data	*phi;

	phi = (t_data *)philo;
	tcond = phi->timelimit;
	fork = phi->fork;
	phi->timestart = get_utime();
	phi->timeeat = phi->timestart;
	philo_wait(phi);
	while ((phi->no_ate != phi->timelimit->no_eat) && !(fork->die_stat))
	{
		if (pick_fork_eat(phi, tcond, fork))
			break ;
		printing(phi, "\033[0;34mis sleeping\033[0m", 0);
		my_usleep(tcond->slp + tcond->eat, phi->timeeat);
		printing(phi, "\033[0;33mis thinking\033[0m", 0);
	}
	fork_down(phi, fork);
	fork->die_stat = 1;
	return (NULL);
}

int	pick_fork_eat(t_data *phi, t_tlim *tcond, t_finfo *fork)
{
	if (phi->tag == 1 || phi->tag == 2)
		return (pickfork_eat_normal(phi, tcond, fork));
	else if (phi->tag == 3)
		return (pickfork_eat_lastodd(phi, tcond, fork));
	return (1);
}

// pick right fork first
int	pickfork_eat_normal(t_data *phi, t_tlim *tcond, t_finfo *fork)
{
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	printing(phi, "\033[0;35mhas taken a fork\033[0m", 0);
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	pthread_mutex_lock(&(fork->lock));
	printing(phi, "\033[0;35mhas taken a fork\033[0m", 0);
	if (printing(phi, "\033[0;32mis eating\033[0m", 0))
		return (1);
	phi->timeeat = get_utime();
	pthread_mutex_unlock(&(fork->lock));
	my_usleep(tcond->eat, phi->timeeat);
	pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
	pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
	phi->no_ate++;
	return (0);
}

// just pick L fork first
int	pickfork_eat_lastodd(t_data *phi, t_tlim *tcond, t_finfo *fork)
{
	pthread_mutex_lock(&(fork->fmutex[phi->num_l]));
	printing(phi, "\033[0;35mhas taken a fork\033[0m", 0);
	pthread_mutex_lock(&(fork->fmutex[phi->num_r]));
	pthread_mutex_lock(&(fork->lock));
	printing(phi, "\033[0;35mhas taken a fork\033[0m", 0);
	if (printing(phi, "\033[0;32mis eating\033[0m", 0))
		return (1);
	phi->timeeat = get_utime();
	pthread_mutex_unlock(&(fork->lock));
	my_usleep(tcond->eat, phi->timeeat);
	pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
	pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
	phi->no_ate++;
	return (0);
}
