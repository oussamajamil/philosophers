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
	if (philo->id_philo % 2)
		usleep(100);
	philo->last_time_eat = ft_time();
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->next->fork);
		printf(" %d :philo %d TAKE YOUR FIRST FORK\n",philo->id_philo,time_action());
		printf(" philo %d TAKE YOUR SCONDE FORK\n",philo->id_philo);
		printf("philo %d eats\n",philo->id_philo);
		usleep(philo->data->time_to_eat);
		philo->cp_time_eat++;
		philo->last_time_eat = ft_time();
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		//
		printf("philo %d sleep\n",philo->id_philo);
		usleep(philo->data->time_to_sleep);
		printf("philo %d thiking\n",philo->id_philo);
	}
	return (0);
}
void ft_pthread(t_data *data)
{
	int i;
	t_philo *tmp;

	i = 0;
	tmp = NULL;
	while (tmp != data->strct && data->strct->next)
	{
		if (i == 0)
		{
			tmp = data->strct;
			i = 1;
		}
		pthread_create(&data->strct->philo,NULL,&action,data->strct);
		data->strct = data->strct->next;
	}
	// ft_check_dead(data);
}