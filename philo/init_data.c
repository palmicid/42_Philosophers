/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:06:44 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/27 10:28:42 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_init_data(t_data *philo, t_forkinfo *fork, t_time_lim *timebox)
{
	int	i;
	long	st_time;

	i = 0;
	st_time = get_utime();
	while (i < timebox->no_ph)
	{
		philo[i].id = i + 1;
		philo[i].left_stat = 0;
		philo[i].right_stat = 0;
		assign_fork(&philo[i], timebox);
		philo[i].no_ate = 0;
		philo[i].fork = fork;
		philo[i].timelimit = timebox;
		philo[i].timestart = st_time;
		philo[i].timedie = 0;
		philo[i].tag = addtag_philo(philo[i].id, timebox->no_ph);
		i++;
	}
}

t_data	*init_philo(t_data *philo, t_forkinfo *fork, t_time_lim *timebox)
{
	philo = (t_data *)malloc(sizeof(t_data) * timebox->no_ph);
	if (!philo)
		return (NULL);
	add_init_data(philo, fork, timebox);
	return (philo);
}

t_forkinfo	*create_fork(t_forkinfo *fork, t_time_lim *timebox)
{
	int	i;

	i = 0;
	fork = (t_forkinfo *)malloc(sizeof(t_forkinfo));
	if (!fork)
		return (NULL);
	fork->fmutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* timebox->no_ph);
	if (!fork->fmutex)
		return (NULL);
	pthread_mutex_init(&(fork->writing), NULL);
	while (i < timebox->no_ph)
	{
		if (pthread_mutex_init(&(fork->fmutex[i]), NULL) != 0)
		{
			free(fork->fmutex);
			free(fork);
			return (NULL);
		}
		i++;
	}
	fork->die_stat = 0;
	return (fork);
}

t_forkinfo	*destroy_fork(t_forkinfo *fork, t_time_lim *timebox)
{
	int	i;

	i = 0;
	while (i < timebox->no_ph)
	{
		pthread_mutex_destroy(&(fork->fmutex[i]));
		i++;
	}
	pthread_mutex_destroy(&(fork->writing));
	free(fork->fmutex);
	free(fork);
	return (NULL);
}

t_data	*destroy_philo(t_data *philo, t_time_lim *timebox)
{
	int	i;

	i = 0;
	while (i < timebox->no_ph)
	{
		philo[i].fork = NULL;
		philo[i].timelimit = NULL;
		i++;
	}
	free(philo);
	return (NULL);
}
