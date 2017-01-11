/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 20:25:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		ft_count(char *argv, t_env *fdf)
{
	char	*line;
	int		fd;

	fdf->nblin = 0;
	fdf->nbcol = 0;
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	fdf->nblin++;
	fdf->nbcol = ft_count_words_sep(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		free(line);
		fdf->nblin++;
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_fill_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;
	int		x;
	int		y;

	x = 0;
	fdf->map = ft_createtab(fdf->nblin, fdf->nbcol);
	while (get_next_line(fd, &line))
	{
		y = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[y] != NULL)
		{
			fdf->map[x][y] = ft_atoi(split_line[y]);
			free(split_line[y]);
			y++;
		}
		free(split_line);
		free(line);
		x++;
	}
	return (0);
}

int		ft_create_map(char *argv)
{
	t_env	fdf;
	int		fd;

	ft_count(argv, &fdf);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	ft_fill_map(fd, &fdf);
	ft_draw_map(&fdf); // Dessiner map avec algo de Bresenham
	free(*(fdf.map));
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
