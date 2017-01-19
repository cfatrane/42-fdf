/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:29 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/19 20:34:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
	else if (ft_check(argv[1]) == -1)
		return (-1);
	else
		ft_fdf(argv[1]);
	return (0);
}
