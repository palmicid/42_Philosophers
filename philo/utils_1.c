/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:37:41 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/18 14:09:03 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_fork(t_data *philo, t_time_lim *timebox)
{
	philo->num_r = philo->id - 1;
	if (philo->id == timebox->no_ph)
		philo->num_l = 0;
	else
		philo->num_l = philo->id;
}

void	ft_putendl_fd(char *str, int fd)
{

}
