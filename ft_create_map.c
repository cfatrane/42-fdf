/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/05 16:23:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		ft_count_nblin(char *argv)
{
	char	*line;
	int		fd;
	int		ord;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	ord = 0;
	while (get_next_line(fd, &line))
		ord++;
	if ((close(fd)) == -1)
		return (-1);
	return (ord);
}

int		ft_count_nbcol(char *argv)
{
	char	*line;
	int		fd;
	int		abs;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	abs = 0;
	get_next_line(fd, &line);
	abs = ft_count_words_sep(line, ' ');
	if ((close(fd)) == -1)
		return (-1);
	return (abs);
}

int		**ft_fill_map(int fd, int nblin, int nbcol)
{
	char	*line;
	char	**split_line;
	int		**tab;
	int		x;
	int		y;

	x = 0;
	tab = ft_createtab(nblin, nbcol);
	while (get_next_line(fd, &line))
	{
		y = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[y] != NULL)
		{
			tab[x][y] = ft_atoi(split_line[y]);
			y++;
		}
		x++;
	}
	return (tab);
}

int		ft_create_map(char *argv)
{
	int		fd;
	int		**tab;
	int		nblin;
	int		nbcol;

	nblin = ft_count_nblin(argv);
	nbcol = ft_count_nbcol(argv);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	tab = ft_fill_map(fd, nblin, nbcol);
	free(tab);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
