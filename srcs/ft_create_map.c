/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/16 20:06:59 by cfatrane         ###   ########.fr       */
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

int		ft_take_color(char*str)
{
	int	i;
	char	*color;
	i = 0;
	while(str[i])
	{
		color[i] = str[i];
		i++;
	}
	color[i] = '\0';
	printf("color = %s", color);
	return (0);
}

int		ft_fill_map(int fd, t_env *fdf)
{
	char	*line;
	char	**split_line;

	int i =0;
	int color;
	fdf->map.map = ft_createtab(fdf->map.nblin, fdf->map.nbcol);
	while (get_next_line(fd, &line))
	{
		fdf->map.x = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[fdf->map.x] != NULL)
		{
		//	printf("line = %s |\n", split_line[fdf->map.x]);
			while(split_line[fdf->map.x][i])
			{
				if (split_line[fdf->map.x][i] == ',')
				{
					i++;
					color = ft_hex_to_dec(ft_strdup_c(split_line[fdf->map.x] +i, ' '));
				printf("color = %d", color);
					//	printf("VIRGULE = ");
				}
			//	printf("char = %c |", split_line[fdf->map.x][i]);
				i++;
			}
			printf("\n");
			i = 0;
			//	printf("char = %c |", split_line[3][i]);
			fdf->map.map[fdf->map.y][fdf->map.x] = ft_atoi(split_line[fdf->map.x]);
			free(split_line[fdf->map.x]);
			fdf->map.x++;
		}
		printf("return\n");
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
