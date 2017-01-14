/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 23:16:57 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_count(char *argv, t_env *fdf)
{
	char	*line;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	fdf->map.nblin++;
	fdf->map.nbcol = ft_count_words_sep(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		free(line);
		fdf->map.nblin++;
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_fill_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;

	fdf->map.map = ft_createtab(fdf->map.nblin, fdf->map.nbcol);
	while (get_next_line(fd, &line))
	{
		fdf->map.y = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[fdf->map.y] != NULL)
		{
			fdf->map.map[fdf->map.x][fdf->map.y] = ft_atoi(split_line[fdf->map.y]);
			free(split_line[fdf->map.y]);
			fdf->map.y++;
		}
		fdf->map.max = ft_max(fdf->map.map[fdf->map.x], fdf->map.nblin);
		if (fdf->map.max > fdf->map.pad)
			fdf->map.pad = fdf->map.max;
		free(split_line);
		free(line);
		fdf->map.x++;
	}
	return (0);
}

int		ft_create_map(char *argv, t_env *fdf)
{
	int		fd;

	ft_count(argv, fdf);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	ft_fill_map(fd, fdf);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
