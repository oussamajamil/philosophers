/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:30:57 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/21 14:47:48 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_time	times;
	t_intger t;
	t_data data;
	int i;

	data.strct = NULL;
	ft_check_params(ac, av);
	ft_remplir_int(&t, ac, av);
	ft_remplir_data(&data,t.number_of_philosophers);
	ft_pthread(&times,&t,&data);
}
