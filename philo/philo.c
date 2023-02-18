/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:43:31 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/18 16:18:04 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(pthread_t *phi_th, t_data *philo, t_time_lim *timebox)
{
	int	i;

	i = 0;
	while (i < timebox->no_ph)
	{
		if (pthread_create(&(phi_th[i]), NULL, &routine, &philo[i]) != 0)
		{
			printf("Failed to create thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

t_data	*process(t_data *philo, t_time_lim *timebox)
{
	int			i;
	pthread_t	*phi_th;

	i = 0;
	phi_th = (pthread_t *)malloc(sizeof(pthread_t) * timebox->no_ph);
	if (phi_th)
	{
		if (create_thread(phi_th, philo, timebox) == 0)
		{
			while (pthread_join(phi_th[i], NULL) == 0)
			{
				i++;
			}
		}
		free(phi_th);
	}
	philo = destroy_philo(philo, timebox);
	return (NULL);
}

void	sub_main(int ac, char **av, t_time_lim *timebox)
{
	t_forkinfo	*fork;
	t_data		*group_philo;

	if (cx_data(ac, av, timebox))
	{
		fork = create_fork(fork, timebox);
		if (fork)
		{
			group_philo = init_philo(group_philo, fork, timebox);
			if (group_philo)
				group_philo = process(group_philo, timebox);
			fork = destroy_fork(fork, timebox);
		}
		else
			printf("Failed to create fork\n");
	}
	else
		error_msg();
}

int	main(int ac, char **av)
{
	t_time_lim	*timebox;
	t_forkinfo	*fork;

	timebox = (t_time_lim *)malloc(sizeof(t_time_lim));
	if (!timebox)
		return (0);
	if (ac == 5 || ac == 6)
		sub_main(ac, av, timebox);
	else
		error_msg();
	free(timebox);
	return (0);
}
