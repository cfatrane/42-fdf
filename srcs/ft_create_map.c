/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/21 11:07:18 by cfatrane         ###   ########.fr       */
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
	if (line)
		free(line);
	while (get_next_line(fd, &line))
	{
		fdf->map.nblin++;
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_fill_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;

	if (!(fdf->map.map = ft_create_tab_two(fdf->map.nbcol, fdf->map.nblin)))
		return (-1);
	while (get_next_line(fd, &line))
	{
		fdf->map.x = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[fdf->map.x] != NULL)
		{
			fdf->map.map[fdf->map.y][fdf->map.x] =
				ft_atoi(split_line[fdf->map.x]);
			free(split_line[fdf->map.x]);
			fdf->map.x++;
		}
		fdf->map.max = ft_max(fdf->map.map[fdf->map.y], fdf->map.nblin);
		if (fdf->map.max > fdf->map.pad)
			fdf->map.pad = fdf->map.max;
		free(split_line);
		free(line);
		fdf->map.y++;
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
