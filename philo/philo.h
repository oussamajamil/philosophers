/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:31:17 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/05 22:03:59 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include<sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_intger
{
	long int	number_of_philosophers;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	number_of_times_each_philosopher_must_eat;
}	t_intger;
typedef struct s_philo
{
	int	id_philo;
	pthread_t		philo;
	long int		times_start;
	long int		time_action;	
	pthread_mutex_t fork;
	long int 		last_time_eat;
	int				cp_time_eat;
	struct s_philo *next;
	t_intger 		*data;
	struct s_data	*ds;
	int 			die;
}	t_philo;

typedef struct s_data
{
	t_philo *strct;
	t_philo	*last;
	int		philo_is_dead;
	pthread_mutex_t write;
}	t_data;

int			ft_atoi(char *str);
int			ft_isnumber(char *str);
int			ft_check_ac(char **str);
void		ft_check_params(int ac, char **av);
void		ft_remplir_int(t_intger *t, int ac, char **av);
t_philo 	*Insert_data(int id,t_data *data);
void		add_back(int id, t_data *data);
void		ft_print_list(t_data *dt);
void		ft_remplir_data(t_data *dt,int ac);
void		ft_pthread(t_data *data);
void		ft_intiale(t_data *data,t_intger *t);
long int 	ft_time();
long int time_action(long int a, long int b);
void		ft_join(t_data *data);
#endif