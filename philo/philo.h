/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:23:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/03/04 15:38:29 by pruangde         ###   ########.fr       */
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
	int				no_ph;
	long			die;
	long			eat;
	long			slp;
	int				no_eat;
}					t_tlim;

typedef struct s_forkinfo
{
	pthread_mutex_t	*fmutex;
	pthread_mutex_t	writing;
	pthread_mutex_t	lock;
	int				die_stat;
}					t_finfo;

typedef struct s_data
{
	int				id;
	int				num_l;
	int				num_r;
	int				no_ate;
	t_finfo			*fork;
	t_tlim			*timelimit;
	long			timestart;
	long			timeeat;
	long			tag;
}					t_data;

// philo
void	cx_daed_philo(t_data *philo, t_tlim *tcond);
int		create_thread(pthread_t *phi_th, t_data *philo, t_tlim *timebox);
t_data	*process(t_data *philo, t_tlim *timebox);
void	sub_main(int ac, char **av, t_tlim *timebox);

// cx_input
int		cx_number(char **av);
int		atoi_philo(char *str);
int		cx_data(int ac, char **av, t_tlim *timebox);
int		cx_zero(t_tlim *timebox);
void	error_msg(void);

// init_data
void	add_init_data(t_data *philo, t_finfo *fork, t_tlim *timebox);
t_data	*init_philo(t_data *philo, t_finfo *fork, t_tlim *timebox);
t_finfo	*create_fork(t_finfo *fork, t_tlim *timebox);
t_finfo	*destroy_fork(t_finfo *fork, t_tlim *timebox);
t_data	*destroy_philo(t_data *philo, t_tlim *timebox);

// routine_1
void	*routine(void *philo);
int		pick_fork_eat(t_data *phi, t_tlim *tcond, t_finfo *fork);
int		pickfork_eat_normal(t_data *phi, t_tlim *tcond, t_finfo *fork);
int		pickfork_eat_lastodd(t_data *phi, t_tlim *tcond, t_finfo *fork);

// routine_2
void	philo_wait(t_data *phi);
int		printing(t_data *phi, char *str, int killmode);

// routine_3
void	fork_down(t_data *phi, t_finfo *fork);

// time.c
long	get_utime(void);
void	my_usleep(long usec, long eat);

// utils_1
void	assign_fork(t_data *philo, t_tlim *timebox);
long	addtag_philo(int id, int max);

#endif
