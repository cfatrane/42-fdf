/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:05:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/02 20:09:06 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_fdf(int fd)
{
	char *line;
	char **tab;
	int i;

	i = 0;
/*	while (get_next_line(fd, &line))
	{
		ft_strsplit



	}
*/

	
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	ft_putstr(*(tab + 2));
	return (0);
}
