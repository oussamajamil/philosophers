/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:46:55 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/12 18:48:51 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->next->fork);
	ft_print(philo, "has taken a fork\n");
	philo->time_action = ft_time();
	ft_print(philo, "is eating\n");
	philo->last_time_eat = ft_time();
	usleep(philo->data->time_to_eat * 1000);
	philo->cp_time_eat++;
	if (philo->cp_time_eat == philo->data
		->number_of_times_each_philosopher_must_eat)
		philo->ds->all_eats++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	ft_print(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	philo->time_action = ft_time();
	ft_print(philo, "is thinking\n");
}

void	*ft_action_tread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_time_eat = ft_time();
	if (philo->id_philo % 2)
		usleep(1000);
	while (philo->ds->philo_is_dead == 0)
		action(philo);
	return (0);
}

void	ft_free_list(t_data *data)
{
	int			i;
	int			nombre_philo;
	t_philo		*tmp;

	i = 0;
	nombre_philo = data->strct->data->number_of_philosophers;
	while (i < nombre_philo)
	{
		pthread_mutex_destroy(&data->strct->fork);
		tmp = data->strct;
		data->strct = data->strct->next;
		free(tmp);
		i++;
	}
	pthread_mutex_destroy(&data->write);
}

void	ft_check_dead(t_data *data)
{
	int	i;

	i = 0;
	while (data->strct)
	{
		if (time_action(data->strct->last_time_eat, ft_time())
			> data->strct->data->time_to_die + 5)
		{
			data->philo_is_dead = 1;
			pthread_mutex_lock(&data->write);
			printf("\033[31m%ld ms %d died\n",
				time_action(data->strct->times_start,
					ft_time()), data->strct->id_philo);
			break ;
		}
		if (data->all_eats == data->strct->data
			->number_of_times_each_philosopher_must_eat)
		{
			data->philo_is_dead = 1;
			break ;
		}
		data->strct = data->strct->next;
	}
	ft_free_list(data);
}

void	ft_pthread(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = NULL;
	data->philo_is_dead = 0;
	data->all_eats = 0;
	pthread_mutex_init(&data->write, NULL);
	while (tmp != data->strct && data->strct->next)
	{
		if (i == 0)
		{
			tmp = data->strct;
			i = 1;
		}
		pthread_create(&data->strct->philo, NULL,
			&ft_action_tread, data->strct);
		usleep(10);
		data->strct = data->strct->next;
	}
	ft_check_dead(data);
}
