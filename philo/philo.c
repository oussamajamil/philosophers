/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:30:57 by ojamil            #+#    #+#             */
/*   Updated: 2022/02/05 22:03:31 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
	
int	main(int ac, char *av[])
{
	t_intger t;
	t_data data;
	int i;

	data.strct = NULL;
	ft_check_params(ac, av);
	ft_remplir_int(&t, ac, av);
	ft_remplir_data(&data,ft_atoi(av[1]));
	ft_intiale(&data,&t);
	ft_pthread(&data);
	ft_join(&data);
}
