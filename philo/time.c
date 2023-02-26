/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:32:22 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/26 21:44:28 by pruangde         ###   ########.fr       */
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

void	my_usleep(long usec)
{
	long	present;

	present = get_utime();
	while ((get_utime() - present) < usec)
		;
	return ;
}
