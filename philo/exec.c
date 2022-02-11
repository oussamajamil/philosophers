/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:33:07 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/06 12:54:12 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *action(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	philo->last_time_eat = ft_time();
	if (philo->id_philo % 2)
		usleep(1000);
	
	while (philo->ds->philo_is_dead == 0)
	{
		pthread_mutex_lock(&philo->fork);
		philo->time_action = ft_time();
		pthread_mutex_lock(&philo->ds->write);
		printf(" philo %d TAKE YOUR FIRST FORK time:%ld\n",philo->id_philo,time_action(philo->times_start,philo->time_action));
		pthread_mutex_unlock(&philo->ds->write);
		pthread_mutex_lock(&philo->next->fork);
		philo->time_action = ft_time();
		pthread_mutex_lock(&philo->ds->write);
		printf(" philo %d TAKE YOUR SCONDE FORK  time:%ld\n",philo->id_philo,time_action(philo->times_start,philo->time_action));
		pthread_mutex_unlock(&philo->ds->write);
		philo->time_action = ft_time();
		// pthread_mutex_lock(&philo->ds->write);
		printf("philo %d eats      time : %ld\n",philo->id_philo,time_action(philo->times_start,philo->time_action));
		// pthread_mutex_unlock(&philo->ds->write);
		philo->cp_time_eat++;
		philo->last_time_eat = ft_time();
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		//
		philo->time_action = ft_time();
		// pthread_mutex_lock(&philo->ds->write);
		printf("philo %d sleep   time:%ld\n",philo->id_philo,time_action(philo->times_start,philo->time_action));
		// pthread_mutex_unlock(&philo->ds->write);
		usleep(philo->data->time_to_sleep * 1000);
		philo->time_action = ft_time();
		// pthread_mutex_lock(&philo->ds->write);
		printf("philo %d thiking   time:%ld\n",philo->id_philo,time_action(philo->times_start,philo->time_action));
		// pthread_mutex_unlock(&philo->ds->write);
	}
	return (0);
}
// ft_print(t_data *data)
// {
// 	pthread_mutex_lock(&data->write);
// 	printf()
// 	pthread_mutex_unlock(&data->write);
// }
void ft_check_dead(t_data *data)
{
	while(data->strct)
	{
		if (time_action(data->strct->last_time_eat ,ft_time()) >= data->strct->data->time_to_die + 5)
		{
			data->philo_is_dead = 1;\
			// pthread_mutex_lock(&data->write);
			printf("\033[31m philo %d is dead time :%ld\n  ",data->strct->id_philo,time_action(data->strct->times_start,data->strct->time_action));
			return;
		}
	}
}

void ft_pthread(t_data *data)
{
	int i;
	t_philo *tmp;

	i = 0;
	tmp = NULL;
	data->philo_is_dead = 0;
	//pthread_mutex_init(&data->write,NULL);
	while (tmp != data->strct && data->strct->next)
	{
		if (i == 0)
		{
			tmp = data->strct;
			i = 1;
		}
		pthread_create(&data->strct->philo,NULL,&action,data->strct);
		usleep(10);
		data->strct = data->strct->next;
	}
	ft_check_dead(data);
}