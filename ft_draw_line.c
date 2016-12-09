/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:38:09 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 17:41:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_line(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;

	y1 = 0;
	while (y1 < nblin * 20)
	{
		x1 = 0;
		y2 = y1;
		while (x1 < (nbcol - 1) * 20)
		{
			x2 = x1 + 20;
			x = x1;
			while (x <= x2)
			{
				mlx_pixel_put(mlx, win, 10 + x, 10 + ((y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))), 0x00FF0000);
				x++;
			}
			x1 = x1 + 20;
		}
		y1 = y1 + 20;
	}
	return (0);
}
