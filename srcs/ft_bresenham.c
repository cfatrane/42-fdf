/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 13:40:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 2;
//double cte1 = 1;
//double cte2 = 2;
int pos = 30;

int	ft_draw_parall_single_col(t_coord *point, t_env *fdf, int line, int col)
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
	t_coord	point;
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

void ft_bresenham_line(t_coord *point, t_env *fdf, int line, int col)
{
	while (point->x < (fdf->nbcol - 1) * 20)
	{
		point->x2 = (point->x + 20) + (cte * (pos * fdf->map.map[line][col + 1]));
		point->y2 = point->y + ((cte / 2) * (pos * fdf->map.map[line][col + 1]));

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
		col++;
		point->x += 20;
		point->x1 = point->x2;
		point->y1 = point->y2;
	}
}

int	ft_draw_parall_lines(t_env *fdf)
{
	t_coord	point;
	int		col;
	int		line;

	line = 0;
	point.y = 0;
	while (point.y < fdf->nblin * 20)
	{
		col = 0;
		point.x = 0;
		point.x1 = point.x + (cte * (pos * fdf->map.map[line][col]));
		point.y1 = point.y + ((cte / 2) * (pos * fdf->map.map[line][col]));
		ft_bresenham_line(&point, fdf, line, col);
		line++;
		point.y += 20;
	}
	return (0);
}
