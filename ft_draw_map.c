/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/07 18:38:38 by cfatrane         ###   ########.fr       */
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
	while (y1 < nblin * 15)
	{
		x1 = 0;
		y2 = y1;
		while (x1 < (nbcol - 1) * 15)
		{
			x2 = x1 + 15;
			x = x1;
			while (x <= x2)
			{
				mlx_pixel_put(mlx, win, 50 + x, 50 + ((y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))), 0x00FF0000);
				x++;
			}
			x1 = x1 + 15;
		}
		y1 = y1 + 15;
	}
	return (0);
}

int	ft_draw_colonne(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int y;

	y1 = 0;
	while (y1 < (nblin - 1) * 15)
	{
		x1 = 0;
		while (x1 < nbcol * 15)
		{
			x2 = x1;
			y2 = y1 + 15;
			y = y1;
			while (y <= y2)
			{
				mlx_pixel_put(mlx, win, 50 + ((x1 + ((x2 - x1) * (y - y1)) / (y2 - y1))), 50 + y, 0x00FFFFFF);
				y++;
			}
			x1 = x1 + 15;
		}
		y1 = y1 + 15;
	}
	return (0);
}


int	ft_draw_parall(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;

	y1 = 0;
	while (y1 < nblin * 15)
	{
		x1 = 0;
		y2 = y1 + 0.5 * 50;
		while (x1 < nbcol * 15)
		{
			x2 = x1 + 0.5 * 50;
			x = x1;
			while (x <= x2)
			{
				mlx_pixel_put(mlx, win, 50 + x, 50 + ((y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))), 0x0000FFFF);
				x++;
			}
			x1 = x1 + 15;
		}
		y1 = y1 + 15;
	}
	return (0);
}


int	ft_draw_map(int **map, int nblin, int nbcol)
{
	void	*mlx;
	void	*win;

	(void)map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "fdf");
	ft_draw_line(map, nblin, nbcol, mlx, win);
	ft_draw_colonne(map, nblin, nbcol, mlx, win);
	ft_draw_parall(map, nblin, nbcol, mlx, win);
	mlx_loop(mlx);
	return (0);
}
