/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:05:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/02 20:46:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**ft_fdf(int fd)
{
	char *line;
	char **abscisse;
	char **chrtab;
	int **tab;
	int i = 0;
	get_next_line(fd, &line);
	abscisse = ft_strsplit(line, ' ');
	chrtab = abscisse;
	while (chrtab[i] != '\0')
	{
		ft_atoi(chrtab[i]);
		ft_putstr(chrtab[i]);
		i++;
	}
/*	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	chrtab = ft_strsplit(line, ' ');
	ft_putstr(*(chrtab + 2));*/
	return (tab);
}
