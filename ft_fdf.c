/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:05:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/02 20:41:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_fdf(int fd)
{
	char *line;
	char **abscisse;
	char **tab = NULL;
	int i = 0;	
	get_next_line(fd, &line);
	abscisse = ft_strsplit(line, ' ');
	tab = abscisse;
	while (tab[i] != '\0')
	{
		ft_atoi(tab[i]);
		ft_putstr(tab[i]);
		i++;
	}
/*	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	ft_putstr(*(tab + 2));*/
	return (0);
}
