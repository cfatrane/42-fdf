/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 14:12:57 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 1;
double cte1 = 0.5;
double cte2 = 0.5;
int pos = 15;

int	ft_draw_parall_col(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;
	int y;
	int col;
	int line;

	col = 0;
	x = 0;
	while (x < nbcol * 20)
	{
		y = 0;
		line = 0;
		x1 = x + (cte * (pos * map[line][col]));
		y1 = y + ((cte / 2) * (pos * map[line][col]));
		while (y < ((nblin - 1) * 20))
		{
			x2 = x + (cte * (pos * map[line + 1][col]));
			y2 = (y + 20) + ((cte / 2) * (pos * map[line + 1][col]));
			ft_draw_line(x1, y1, x2, y2, mlx, win);
			line++;
			y = y + 20;
			x1 = x2;
			y1 = y2;
		}
		col++;
		x = x + 20;
	}
	return (0);
}

int	ft_draw_parall_line(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;
	int y;
	int col;
	int line;

	line = 0;
	y = 0;
	while (y < nblin * 20)
	{
		col = 0;
		x = 0;
		x1 = x + (cte * (pos * map[line][col]));
		y1 = y + ((cte / 2) * (pos * map[line][col]));
		while (x < (nbcol - 1 ) * 20)
		{
			x2 = (x + 20) + (cte * (pos * map[line][col + 1]));
			y2 = y + ((cte / 2) * (pos * map[line][col + 1]));
			ft_draw_line(x1,y1, x2, y2, mlx, win);
			col++;
			x = x + 20;
			x1 = x2;
			y1 = y2;
		}
		line++;
		y = y + 20;
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
	ft_draw_parall_line(map, nblin, nbcol, mlx, win);
	ft_draw_parall_col(map, nblin, nbcol, mlx, win);
	mlx_loop(mlx);
	return (0);
}
