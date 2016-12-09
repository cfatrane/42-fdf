/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 14:57:54 by cfatrane         ###   ########.fr       */
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

int	ft_draw_colonne(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int y;

	y1 = 0;
	while (y1 < (nblin - 1) * 20)
	{
		x1 = 0;
		while (x1 < nbcol * 20)
		{
			x2 = x1;
			y2 = y1 + 20;
			y = y1;
			while (y <= y2)
			{
				mlx_pixel_put(mlx, win, 10 + ((x1 + ((x2 - x1) * (y - y1)) / (y2 - y1))), 10 + y, 0x00FFFFFF);
				y++;
			}
			x1 = x1 + 20;
		}
		y1 = y1 + 20;
	}
	return (0);
}

int	ft_draw_parall_col(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int X1;
	int Y1;
	int X2;
	int Y2;
	int x;
	int y;
	int c;
	int col;
	int line;
	double cte = 5;
	int k = 50;

	line = 0;
	y = 0;
	while (y < (nblin - 1) * 20)
	{
		printf("LIGNE = %d\n\n", y);
		col = 0;
		x = 0;
		X1 = x + cte * (15 * map[line][col]);
		Y1 = y + (cte / 2) *  (15 * map[line][col]);
		while (x < nbcol * 20)
		{
			X2 = (x + 20) + cte * (15 * map[line + 1][col]);
			Y2 = (y + 20) + (cte / 2) * (15 * map[line + 1][col]);
			printf("X1 vaut = %d\n", X1);
			printf("Y1 vaut = %d\n", Y1);
			printf("X2 vaut = %d\n", X2);
			printf("Y2 vaut = %d\n", Y2);
			c = Y1;
			while (c <= Y2)
			{
				mlx_pixel_put(mlx, win, 50 + (X1 + ((X2 - X1) * (c - Y1)) / (Y2 - Y1)), 50 + c, 0x000000FF);
				mlx_pixel_put(mlx, win, k + X1, k + Y1, 0x00FF0000);
				c++;
			}
			printf("--------------\n");
			col++;
			x = x + 20;
			X1 = X2;
			Y1 = Y2;
		}
		printf("--------------------------\n");
		printf("NEW LINE NEW LINE NEW LINE\n");
		printf("--------------------------\n");
		line++;
		y = y + 20;
	}
	return (0);
}

int	ft_draw_parall_line(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int X1;
	int Y1;
	int X2;
	int Y2;
	int x;
	int y;
	int c;
	int col;
	int line;
	double cte = 5;
	int k = 50;

	line = 0;
	y = 0;
	while (y < nblin * 20) // OK
	{
//		printf("LIGNE = %d\n\n", y);
		col = 0;
		x = 0;
		X1 = x + cte * (15 * map[line][col]);
		Y1 = y + ((cte / 2) * (15 * map[line][col]));
		while (x < nbcol * 20) // OK
		{
			X2 = (x + 20) + cte * (15 * map[line][col + 1]);
			Y2 = y + (cte / 2) * (15 * map[line][col + 1]);
/*			printf("X1 vaut = %d\n", X1);
			printf("Y1 vaut = %d\n", Y1);
			printf("X2 vaut = %d\n", X2);
			printf("Y2 vaut = %d\n", Y2);*/
			c = X1;
			while (c <= X2)
			{
				mlx_pixel_put(mlx, win, 50 + c, 50 + (Y1 + (ft_abs(Y2 - Y1) * (c - X1)) / ft_abs(X2 - X1)), 0x00FF0000);
				c++;
			}
//			printf("--------------\n");
			col++;
			x = x + 20;
			X1 = X2;
			Y1 = Y2;
		}
/*		printf("--------------------------\n");
		printf("NEW LINE NEW LINE NEW LINE\n");
		printf("--------------------------\n");*/
		line++;
		y = y + 20; // OK
	}
	return (0);
}

int	ft_draw_map(int **map, int nblin, int nbcol)
{
	void	*mlx;
	void	*win;

	(void)map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 1500, "fdf");
//	ft_putnbr(map[8][6]);
//	ft_draw_line(map, nblin, nbcol, mlx, win);
//	ft_draw_colonne(map, nblin, nbcol, mlx, win);
	ft_draw_parall_line(map, nblin, nbcol, mlx, win);
	ft_draw_parall_col(map, nblin, nbcol, mlx, win);
	mlx_loop(mlx);
	return (0);
}
