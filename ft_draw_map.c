/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 16:35:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 1;
double cte1 = 0.5;
double cte2 = 0.5;
int pos = 15;

int	ft_draw_parall_col(int **map, t_env *fdf)
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
	while (x < fdf->nbcol * 20)
	{
		y = 0;
		line = 0;
		x1 = x + (cte * (pos * map[line][col]));
		y1 = y + ((cte / 2) * (pos * map[line][col]));
		while (y < ((fdf->nblin - 1) * 20))
		{
			x2 = x + (cte * (pos * map[line + 1][col]));
			y2 = (y + 20) + ((cte / 2) * (pos * map[line + 1][col]));
			ft_draw_line(x1, y1, x2, y2, fdf);
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

int	ft_draw_parall_line(int **map, t_env *fdf)
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
	while (y < fdf->nblin * 20)
	{
		col = 0;
		x = 0;
		x1 = x + (cte * (pos * map[line][col]));
		y1 = y + ((cte / 2) * (pos * map[line][col]));
		while (x < (fdf->nbcol - 1 ) * 20)
		{
			x2 = (x + 20) + (cte * (pos * map[line][col + 1]));
			y2 = y + ((cte / 2) * (pos * map[line][col + 1]));
			ft_draw_line(x1,y1, x2, y2, fdf);
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

int	ft_draw_map(int **map, t_env *fdf)
{

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1500, 1500, "fdf");
	ft_draw_parall_line(map, fdf);
	ft_draw_parall_col(map, fdf);
	mlx_key_hook(fdf->win, key_hook, &fdf);
//	mlx_expose_hook(fdf->win, expose_hook, &fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
