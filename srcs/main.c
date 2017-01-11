/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:29 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/05 15:46:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		perror("Usage : ./fdf <filename> [ case_size z_size ]");
	else
		ft_create_map(argv[1]);

}
