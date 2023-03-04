/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:09:23 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 13:07:49 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_down(t_data *phi, t_finfo *fork)
{
	// if (phi->right_stat == 1)
	// 	pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
	// if (phi->left_stat == 1)
	// 	pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
	//pthread_mutex_unlock(&(fork->lock));
	pthread_mutex_unlock(&(fork->fmutex[phi->num_r]));
	pthread_mutex_unlock(&(fork->fmutex[phi->num_l]));
	pthread_mutex_unlock(&(fork->writing));
	pthread_mutex_unlock(&(fork->lock));
	return ;
}
