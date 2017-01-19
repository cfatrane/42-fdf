/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:48:04 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/19 13:33:31 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_check_data(char *argv)
{
	char	*line;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	if (get_next_line(fd, &line) == 0 || get_next_line(fd, &line) == -1)
	{
		ft_putendl_fd("Na data found", 2);
		return (-1);
	}
	return (0);
}

int	ft_check_line(char *argv)
{
	char	*line;
	int		c1;
	int		c2;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	c1 = ft_count_words_sep(line, ' ');
	while (get_next_line(fd, &line))
	{
		c2 = ft_count_words_sep(line, ' ');
		if (c1 != c2)
		{
			ft_putendl_fd("Found wrong line length. Exiting.", 2);
			return (-1);
		}
		c1 = ft_count_words_sep(line, ' ');
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int	ft_check(char *argv)
{
	if (ft_check_data(argv) == -1)
		return (-1);
	if (ft_check_line(argv) == -1)
		return (-1);
	return (0);
}
