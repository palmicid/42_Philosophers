/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:23:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/03 00:44:58 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_time_lime
{
	int	no_ph;		// no. of philo
	int	die;		// time to die
	int	eat;		// time to eat
	int	slp;		// time to sleep
	int	no_eat;		// no. time philo must eat
}		t_time_lim;

typedef struct s_data
{
	int	id;
	int	time;
}		t_data;



// philo

// cx_input
int	cx_number(char **av);
int	atoi_philo(char *str);
int	cx_data(int ac, char **av, t_time_lim *timebox);

// process_1


// routine_1
void	*routine(t_data *phi);

#endif
