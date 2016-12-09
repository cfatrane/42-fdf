/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:34:31 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 18:34:34 by cfatrane         ###   ########.fr       */
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

int	ft_draw_cas_un_deux(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, 50 + x, 50 + ((y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_cas_trois_quatre(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x2;
	while (x <= x1)
	{
		mlx_pixel_put(mlx, win, 50 + x, 50 + ((y2 + ((y1 - y2) * (x - x2)) / (x1 - x2))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_cas_cinq_six(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = y1;
	while (x <= y2)
	{
		mlx_pixel_put(mlx, win, 50 + ((x1 + ((x2 - x1) * (x - y1)) / (y2 - y1))), 50 + x, 0x00FFFFFF);
		x++;
	}
	return (0);
}

int	ft_draw_cas_sept_huit(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = y1;
	while (x <= y2)
	{
		mlx_pixel_put(mlx, win, 50 + ((x1 + ((x2 - x1) * (x - y1)) / (y2 - y1))), 50 + x, 0x00FFFFFF);
		x++;
	}
	return (0);
}
