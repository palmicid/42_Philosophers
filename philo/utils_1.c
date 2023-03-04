/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:37:41 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 12:37:07 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_fork(t_data *philo, t_tlim *timebox)
{
	philo->num_r = philo->id - 1;
	if (philo->id == timebox->no_ph)
		philo->num_l = 0;
	else
		philo->num_l = philo->id;
}

long	addtag_philo(int id, int max)
{
	if ((id % 2) == 0)
		return (2);
	else if (id == max && (id != 1))
		return (3);
	else
		return (1);
}
