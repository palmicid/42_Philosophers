/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:23:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/02/18 16:18:51 by pruangde         ###   ########.fr       */
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

typedef struct s_time_lim
{
	int				no_ph;		// no. of philo
	unsigned long	die;		// time to die
	unsigned long	eat;		// time to eat
	unsigned long	slp;		// time to sleep
	int				no_eat;		// no. time philo must eat
}					t_time_lim;

typedef struct s_forkinfo
{
	pthread_mutex_t	*fmutex;
	//pthread_mutex_t diemutex;
	int				die_stat;	// 1 == alive , 0 == die
}		t_forkinfo;

typedef struct s_data
{
	int				id;
	int				left_stat;		// 0 not hold
	int				right_stat;		// 1 holding
	int				num_l;			// fork number to pick up
	int				num_r;
	int				no_ate;
	t_forkinfo		*fork;
	t_time_lim		*timelimit;
	unsigned long	timestart;
	unsigned long	timedie;
	
}					t_data;

// philo
t_data		*process(t_data *philo, t_time_lim *timebox);

// cx_input
int				cx_number(char **av);
int				atoi_philo(char *str);
int				cx_data(int ac, char **av, t_time_lim *timebox);
int				cx_zero(t_time_lim *timebox);
void			error_msg(void);

// init_data
void			add_init_data(t_data *philo, t_forkinfo *fork, t_time_lim *timebox);
t_data			*init_philo(t_data *philo, t_forkinfo *fork, t_time_lim *timebox);
t_forkinfo		*create_fork(t_forkinfo *fork, t_time_lim *timebox);
t_forkinfo		*destroy_fork(t_forkinfo *fork, t_time_lim *timebox);
t_data			*destroy_philo(t_data *philo, t_time_lim *timebox);

// routine_1
void			*routine(t_data *phi);


// time.c
unsigned long	get_time(void);

// utils_1
void			assign_fork(t_data *philo, t_time_lim *timebox);


#endif
