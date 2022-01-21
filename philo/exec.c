/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:33:07 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/21 14:49:40 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *action(void *arg)
{
	printf("hello\n");
	return (0);
}
void ft_pthread(t_time *times,t_intger *t,t_data *data)
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
		// printf("%d\n",data->strct->id_philo);
		pthread_create(&data->strct->philo,NULL,&action,NULL);
		sleep(1);
		data->strct = data->strct->next;
	}
	
}