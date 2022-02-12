/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:25:16 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/12 18:49:51 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*insertdata(int id, t_data *data)
{
	t_philo	*dt;

	dt = (t_philo *)malloc(sizeof(t_philo));
	if (!dt)
		return (NULL);
	dt->id_philo = id;
	dt->last_time_eat = 0;
	dt->next = NULL;
	dt->cp_time_eat = 0;
	dt->times_start = ft_time();
	dt->ds = data;
	pthread_mutex_init(&dt->fork, NULL);
	return (dt);
}

void	add_back(int id, t_data *data)
{
	t_philo	*philo;
	t_philo	*last;

	philo = insertdata(id, data);
	if (!philo)
		return ;
	if (data->strct)
	{
		last = data->last;
		last->next = philo;
		philo->next = data->strct;
	}
	else
		data->strct = philo;
	data->last = philo;
}

void	ft_remplir_data(t_data *dt, int ac)
{
	int	i;

	i = 1;
	while (i <= ac)
	{
		add_back(i, dt);
		i++;
	}
}

void	ft_print_list(t_data *dt)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = NULL;
	while (tmp != dt->strct && dt->strct->next)
	{
		if (i == 0)
		{
			tmp = dt->strct;
			i = 1;
		}
		printf("%d\n", dt->strct->id_philo);
		dt->strct = dt->strct->next;
	}
}

void	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->ds->write);
	printf("%ld ms %d  %s", time_action(philo->times_start, ft_time()),
		philo->id_philo, msg);
	pthread_mutex_unlock(&philo->ds->write);
}
