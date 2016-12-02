/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:29 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/02 14:27:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int fd;

	fd = (open(argv[1], O_RDONLY));
	if (argc != 2)
		perror("Usage : ./fdf <filename> [ case_size z_size ]");
	else
		ft_fdf(fd);

}
