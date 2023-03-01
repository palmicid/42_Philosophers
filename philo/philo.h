/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:23:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/01 18:47:17 by pruangde         ###   ########.fr       */
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
	long			die;		// time to die
	long			eat;		// time to eat
	long			slp;		// time to sleep
	int				no_eat;		// no. time philo must eat
}					t_time_lim;

typedef struct s_forkinfo
{
	pthread_mutex_t	*fmutex;
	pthread_mutex_t writing;
	int				die_stat;
}					t_forkinfo;

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
	long			timestart;
	long			timedie;
	long			tag;
	
}					t_data;

// philo
void			cx_daed_philo(t_data *philo, t_time_lim *tcond);
int				create_thread(pthread_t *phi_th, t_data *philo, t_time_lim *timebox);
t_data			*process(t_data *philo, t_time_lim *timebox);
void			sub_main(int ac, char **av, t_time_lim *timebox);

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
int				pick_fork_eat(t_data *phi, t_time_lim *tcond, t_forkinfo *fork);
int				pickfork_eat_normal(t_data *phi, t_time_lim *tcond, t_forkinfo *fork);
int				philo_sleep_think(t_data *phi, t_time_lim *tcond);
int				pickfork_eat_lastodd(t_data *phi, t_time_lim *tcond, t_forkinfo *fork);

// routine_2
int				cx_death(int stat);
int				cal_upickeat(t_data *phi, t_time_lim *tcond, t_forkinfo *fork);
int				cal_usleepthink(t_data *phi, t_time_lim *tcond, long tslp);
void			philo_wait(t_data *phi, t_forkinfo *fork);
int				printing(t_data *phi, char *str, int killmode);

// routine_3
void			fork_down(t_data *phi, t_forkinfo *fork);

// time.c
long			get_utime(void);
void			my_usleep(long usec);

// utils_1
void			assign_fork(t_data *philo, t_time_lim *timebox);
long			addtag_philo(int id, int max);

#endif
