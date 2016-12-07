/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/07 16:50:21 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		ft_count_nblin(char *argv)
{
	char	*line;
	int		fd;
	int		nblin;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	nblin = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		nblin++;
	}
	if ((close(fd)) == -1)
		return (-1);
	return (nblin);
}

int		ft_count_nbcol(char *argv)
{
	char	*line;
	int		fd;
	int		nbcol;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	nbcol = ft_count_words_sep(line, ' ');
	free(line);
	if ((close(fd)) == -1)
		return (-1);
	return (nbcol);
}

int		**ft_fill_map(int fd, int nblin, int nbcol)
{
	char	*line;
	char	**split_line;
	int		**map;
	int		x;
	int		y;

	x = 0;
	map = ft_createtab(nblin, nbcol);
	while (get_next_line(fd, &line))
	{
		y = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[y] != NULL)
		{
			map[x][y] = ft_atoi(split_line[y]);
			free(split_line[y]);
			y++;
		}
		free(split_line);
		free(line);
		x++;
	}
	return (map);
}

int		ft_create_map(char *argv)
{
	int		fd;
	int		**map;
	int		nblin;
	int		nbcol;

	nblin = ft_count_nblin(argv);
	nbcol = ft_count_nbcol(argv);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	map = ft_fill_map(fd, nblin, nbcol);
	ft_draw_map(map, nblin, nbcol); // Dessiner map avec algo de Bresenham
	free(*map);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
