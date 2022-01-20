/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:41:16 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/20 16:37:37 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	figure_time(t_time t1)
{
	long int	i;
	long int	j;

	gettimeofday(&t1.t2, NULL);
	i = (t1.t1.tv_sec * 1000 * 1000 + t1.t1.tv_usec) / 1000;
	j = (t1.t2.tv_sec * 1000 * 1000 + t1.t2.tv_usec) / 1000;
	return (j - i);
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