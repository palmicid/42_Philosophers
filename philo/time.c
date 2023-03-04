/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:32:22 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 13:26:22 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_utime(void)
{
	struct timeval	time;
	long	longtime;

	gettimeofday(&time, NULL);
	longtime = (time.tv_sec * 1000000) + time.tv_usec;
	return (longtime);
}

void	my_usleep(long usec, long eat)
{
	long	wakeup;

	wakeup = eat + usec;
	while (get_utime() <= wakeup)
		;
	return ;
}
