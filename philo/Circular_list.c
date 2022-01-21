/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:25:16 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/21 13:21:21 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *Insert_data(int id)
{
	t_philo *dt;

	dt = (t_philo *)malloc(sizeof(t_philo));
	if (!dt)
		return (NULL);
	dt->id_philo = id;
	dt->last_time_eat = 0;
	dt->next = NULL;
	dt->cp_time_eat = 0;
	return (dt);
}

void add_back(int id, t_data *data)
{
	t_philo *philo;
	t_philo *last;

	philo = Insert_data(id);
	if (!philo)
		return ;
	if (data->strct)
	{
		last = data->last;
		last->next = philo;
		philo->next = data->strct;
	}
	else
	{
		data->strct = philo;
	}
	data->last = philo;
}

void	ft_remplir_data(t_data *dt, int ac)
{
	int i;

	i = 1;
	while (i <= ac)
	{
		add_back(i,dt);
		i++;
	}
	
}

void ft_print_list(t_data *dt)
{
	int i;
	t_philo *tmp;

	i = 0;
	tmp = NULL;
	while (tmp != dt->strct && dt->strct->next)
	{
		if (i == 0)
		{
			tmp = dt->strct;
			i = 1;
		}
		printf("%d\n",dt->strct->id_philo);
		dt->strct = dt->strct->next;
	}
}