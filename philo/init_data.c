/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:06:44 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 15:37:54 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_init_data(t_data *philo, t_finfo *fork, t_tlim *timebox)
{
	int		i;

	i = 0;
	while (i < timebox->no_ph)
	{
		philo[i].id = i + 1;
		assign_fork(&philo[i], timebox);
		philo[i].no_ate = 0;
		philo[i].fork = fork;
		philo[i].timelimit = timebox;
		philo[i].timestart = 0;
		philo[i].timeeat = 0;
		philo[i].tag = addtag_philo(philo[i].id, timebox->no_ph);
		i++;
	}
}

t_data	*init_philo(t_data *philo, t_finfo *fork, t_tlim *timebox)
{
	philo = (t_data *)malloc(sizeof(t_data) * timebox->no_ph);
	if (!philo)
		return (NULL);
	add_init_data(philo, fork, timebox);
	return (philo);
}

t_finfo	*create_fork(t_finfo *fork, t_tlim *timebox)
{
	int	i;

	i = 0;
	fork = (t_finfo *)malloc(sizeof(t_finfo));
	if (!fork)
		return (NULL);
	fork->fmutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* timebox->no_ph);
	if (!fork->fmutex)
		return (NULL);
	pthread_mutex_init(&(fork->writing), NULL);
	pthread_mutex_init(&(fork->lock), NULL);
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

t_finfo	*destroy_fork(t_finfo *fork, t_tlim *timebox)
{
	int	i;

	i = 0;
	while (i < timebox->no_ph)
	{
		pthread_mutex_destroy(&(fork->fmutex[i]));
		i++;
	}
	pthread_mutex_destroy(&(fork->writing));
	pthread_mutex_destroy(&(fork->lock));
	free(fork->fmutex);
	free(fork);
	return (NULL);
}

t_data	*destroy_philo(t_data *philo, t_tlim *timebox)
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
