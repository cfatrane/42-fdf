/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 14:49:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 2;
//double cte1 = 1;
//double cte2 = 2;
int pos = 30;

int	ft_draw_parall_single_col(t_point *point, t_env *fdf, int line, int col)
{
	while (point->y < ((fdf->nblin - 1) * 20))
	{
		point->x2 = point->x + (cte * (pos * fdf->map.map[line + 1][col]));
		point->y2 = (point->y + 20) + ((cte / 2) * (pos * fdf->map.map[line + 1][col]));

		int dx = abs(point->x2-point->x1), sx = point->x1 < point->x2 ? 1 : -1;
		int dy = abs(point->y2 - point->y1), sy = point->y1 < point->y2 ? 1 : -1; 
		int err = (dx>dy ? dx : -dy)/2, e2;

		for(;;)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, point->x1, point->y1, 0x00FFFFFF);
			if (point->x1 == point->x2 && point->y1==point->y2) break;
			e2 = err;
			if (e2 >-dx) { err -= dy ; point->x1 += sx; }
			if (e2 < dy) { err += dx ; point->y1 += sy; }
		}
		line++;
		point->y += 20;
		point->x1 = point->x2;
		point->y1 = point->y2;
	}
	return (0);
}

int	ft_draw_parall_collumns(t_env *fdf)
{
	t_point	point;
	int		col;
	int		line;

	col = 0;
	point.x = 0;
	while (point.x < fdf->nbcol * 20)
	{
		point.y = 0;
		line = 0;
		point.x1 = point.x + (cte * (pos * fdf->map.map[line][col]));
		point.y1 = point.y + ((cte / 2) * (pos * fdf->map.map[line][col]));
		ft_draw_parall_single_col(&point, fdf, line, col);
		col++;
		point.x += 20;
	}
	return (0);
}
/*
void ft_bresenham_line(t_point *point, t_env *fdf)
{
	int dx = abs(point->x2-point->x1);
	int sx = point->x1 < point->x2 ? 1 : -1;
	int dy = abs(point->y2 - point->y1);
	int sy = point->y1 < point->y2 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2;
	int e2;

	for(;;)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, point->x1, point->y1, 0x00FFFFFF);
		if (point->x1 == point->x2 && point->y1==point->y2)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			point->x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			point->y1 += sy;
		}
	}
}
*/
void	ft_bresenham_line(t_env *fdf)
{
	int delta_x;
	int delta_y;
	int eps;
	int y;
	int x;

	delta_x = fdf->point.x2 - fdf->point.x1;
	delta_y = fdf->point.y2 - fdf->point.y1;
	eps = 0;
	y = fdf->point.y1;
	x = fdf->point.x1;
	while (x <= fdf->point.x2)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x00FFFFFF);
		if (2 * (eps + delta_y) < delta_x)
			eps = eps + delta_y;
		else
		{
			y = y + 1;
			eps = eps + delta_y - delta_x;
		}
		x = x + 1;
	}
}


int		ft_draw_parall_lines(t_env *fdf)
{
	int		col;
	int		line;

	line = 0;
	fdf->point.y = 0;
	while (fdf->point.y < fdf->nblin * 20)
	{
		col = 0;
		fdf->point.x = 0;
		fdf->point.x1 = fdf->point.x + (cte * (pos * fdf->map.map[line][col]));
		fdf->point.y1 = fdf->point.y + ((cte / 2) * (pos * fdf->map.map[line][col]));
		while (fdf->point.x < (fdf->nbcol - 1) * 20)
		{
			fdf->point.x2 = (fdf->point.x + 20) + (cte * (pos * fdf->map.map[line][col + 1]));
			fdf->point.y2 = fdf->point.y + ((cte / 2) * (pos * fdf->map.map[line][col + 1]));
			ft_bresenham_line(fdf);
			col++;
			fdf->point.x += 20;
			fdf->point.x1 = fdf->point.x2;
			fdf->point.y1 = fdf->point.y2;
		}
		line++;
		fdf->point.y += 20;
	}
	return (0);
}
