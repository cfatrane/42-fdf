/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:48:04 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/21 12:33:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_check_data(char *argv, char *line)
{
	int		fd;
	int		ret;

	line = "\0";
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret == 0 || ret == -1)
	{
		ft_putendl_fd("Na data found", 2);
		return (-1);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int	ft_check_line(char *argv, char *line)
{
	int		c;
	int		fd;

	line = "\0";
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	c = ft_count_words_sep(line, ' ');
	while (get_next_line(fd, &line))
	{
		if (c != ft_count_words_sep(line, ' '))
		{
			ft_putendl_fd("Found wrong line length. Exiting.", 2);
			return (-1);
		}
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int	ft_check(char *argv)
{
	char	*line;

	line = "\0";
	if (ft_check_data(argv, line) == -1)
		return (-1);
	if (ft_check_line(argv, line) == -1)
		return (-1);
	return (0);
}
