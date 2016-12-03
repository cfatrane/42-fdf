/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:05:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/03 21:28:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		ft_count_backslash(char *buf)
{
	static int	backslash = 0;
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			ft_putnbr(backslash);
			backslash++;
			ft_putchar(' ');
		}
		i++;
	}
	return (backslash);
}

int		ft_count_abscisse(int fd)
{
	//	char	*line;
	int		abs = 0;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		abs = ft_count_backslash(buf);
	}
	ft_putchar('\n');
	ft_putnbr(abs);
	return (abs);





	/*	while (get_next_line(fd, &line))
		{
		ft_putnbr(abs);
		ft_putchar('\n');
		abs++;
		}*/
	return (abs);
}

/*int		ft_count_ordonnée(int fd)
  {





  }*/

/*int		**createtab(int abs, int nbcol)
  {
  int **tableau = (int **)malloc(sizeof(int*)* abs);
  int *tableau2 = (int *)malloc(sizeof(int)*nbCol* abs);
  for(int i = 0 ; i < abs ; i++){
  tableau[i] = &tableau2[i*nbCol];
  }
  return tableau;
  }*/

int	**ft_fdf(int fd)
{
	char	*line;
	char	**tab_line;
	int		**tab;
	int count = ft_count_abscisse(fd);
	int i;
	int point = 0;
	int k = 0;

	tab = (int**)malloc(sizeof(*tab) * count);
	//	t_position p;
	//	ft_memset(&p, 0, sizeof(p));
	//	tab = (int**)malloc(sizeof(*tab));

	while (get_next_line(fd, &line))
	{
		i = 0;
		tab_line = ft_strsplit(line, ' ');
		ft_putnbr(ft_strlen(tab_line[i]));
		ft_putchar('\n');
		while (tab_line[i] != NULL)
		{
			point = ft_atoi(tab_line[i]);
			tab[k][i] = point;
			i++;
		}
		k++;
	}
	k = 0;
	i = 0;
	while (k < 11)
	{
		while (i < 19)
		{
			ft_putnbr(tab[k][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		k++;
	}
	return (tab);
}
