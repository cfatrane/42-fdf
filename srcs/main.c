/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:29 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/02 13:13:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int fd;

	if ((fd = (open(argv[1], O_RDONLY) == -1)))
		return (-1);
	if (argc != 2)
		perror("Usage : ./fdf <filename> [ case_size z_size ]");
	else if (!argv[1])
		perror("No file argv[1]");
	else
		ft_fdf(fd);




}
