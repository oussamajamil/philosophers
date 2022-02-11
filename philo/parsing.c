/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:41:16 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/05 22:08:10 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int ft_time()
{
	struct timeval	t1;
	gettimeofday(&t1, NULL);
	return (t1.tv_sec * 1000 + t1.tv_usec / 1000);
}
// ft_print_lock_unlock(t_philo *philo,char *msg)
// {
	
// }

long int time_action(long int a, long int b)
{
	return (b - a);
}

void	ft_check_params(int ac, char **av)
{
	if (!(ac >= 5 && ac <= 6 && ft_check_ac(av)))
	{
		printf("Eroor\n");
		exit(0);
	}
}

void	ft_remplir_int(t_intger *t, int ac, char **av)
{
	t->number_of_philosophers = ft_atoi(av[1]);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep= ft_atoi(av[4]);
	if (ac == 6)
		t->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		t->number_of_times_each_philosopher_must_eat = -1;
}

void	ft_intiale(t_data *data,t_intger *t)
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
		data->strct->data = t;
		data->strct = data->strct->next;
	}
}

void		ft_join(t_data *data)
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
		pthread_join(data->strct->philo,NULL);
		data->strct = data->strct->next;
	}
}
