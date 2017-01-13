/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 16:06:31 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte1 = 2;
double cte2 = 2;
int pos_iso = 30;

int	ft_draw_iso_collumns(t_env *fdf)
{
	int		col;
	int		line;

	col = 0;
	fdf->point.x = 0;
	while (fdf->point.x < fdf->nbcol * 20)
	{
		fdf->point.y = 0;
		line = 0;
		fdf->point.x1 = cte1 * fdf->point.x - cte2 * fdf->point.y;
		fdf->point.y1 = (pos_iso * fdf->map.map[line][col]) + (cte1 / 2) * fdf->point.x + (cte2 / 2) * fdf->point.y;
		while (fdf->point.y < ((fdf->nblin - 1) * 20))
		{
			fdf->point.x2 = cte1 * fdf->point.x - cte2 * fdf->point.y;
			fdf->point.y2 = (pos_iso * fdf->map.map[line + 1][col]) + (cte1 / 2) * fdf->point.x + (cte2 / 2) * (fdf->point.y + 20);
			ft_bresenham_col(fdf);
			line++;
			fdf->point.y += 20;
			fdf->point.x1 = fdf->point.x2;
			fdf->point.y1 = fdf->point.y2;
		}
		col++;
		fdf->point.x += 20;
	}
	return (0);
}

int		ft_draw_iso_lines(t_env *fdf)
{
	int		col;
	int		line;

	line = 0;
	fdf->point.y = 0;
	while (fdf->point.y < fdf->nblin * 20)
	{
		col = 0;
		fdf->point.x = 0;
		fdf->point.x1 = cte1 * fdf->point.x - cte2 * fdf->point.y;
		fdf->point.y1 = (pos_iso * fdf->map.map[line][col]) + (cte1 / 2) * fdf->point.x + (cte2 / 2) * fdf->point.y;
		while (fdf->point.x < (fdf->nbcol - 1) * 20)
		{
			fdf->point.x2 = cte1 * (fdf->point.x + 20)- cte2 * fdf->point.y;
			fdf->point.y2 = (pos_iso * fdf->map.map[line][col + 1]) + (cte1 / 2) * fdf->point.x + (cte2 / 2) * (fdf->point.y + 20);
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

