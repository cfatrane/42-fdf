/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 22:38:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_iso_collumns(t_env *fdf)
{
	int		col;
	int		line;
	col = 0;
	fdf->point.x = 0;
	while (fdf->point.x < fdf->map.nbcol * fdf->point.spc)
	{
		fdf->point.y = 0;
		line = 0;
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * fdf->point.y;
		fdf->point.y1 = (fdf->point.pos * fdf->map.map[line][col]) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y;
		while (fdf->point.y < ((fdf->map.nblin - 1) * fdf->point.spc))
		{
			fdf->point.x2 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * (fdf->point.y + fdf->point.spc);
			fdf->point.y2 = (fdf->point.pos * fdf->map.map[line + 1][col]) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * (fdf->point.y + fdf->point.spc);
			ft_bresenham(fdf);
			line++;
			fdf->point.y += fdf->point.spc;
			fdf->point.x1 = fdf->point.x2;
			fdf->point.y1 = fdf->point.y2;
		}
		col++;
		fdf->point.x += fdf->point.spc;
	}
	return (0);
}

int		ft_draw_iso_lines(t_env *fdf)
{
	int		col;
	int		line;

	line = 0;
	fdf->point.y = 0;
	while (fdf->point.y < fdf->map.nblin * fdf->point.spc)
	{
		col = 0;
		fdf->point.x = 0;
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * fdf->point.y;
		fdf->point.y1 = (fdf->point.pos * fdf->map.map[line][col]) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y;
		while (fdf->point.x < (fdf->map.nbcol - 1) * fdf->point.spc)
		{
			fdf->point.x2 = fdf->point.cte1 * (fdf->point.x + fdf->point.spc)- fdf->point.cte2 * fdf->point.y;
			fdf->point.y2 = (fdf->point.pos * fdf->map.map[line][col + 1]) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * (fdf->point.y + fdf->point.spc);
			ft_bresenham(fdf);
			col++;
			fdf->point.x += fdf->point.spc;
			fdf->point.x1 = fdf->point.x2;
			fdf->point.y1 = fdf->point.y2;
		}
		col++;
		line++;
		fdf->point.y += fdf->point.spc;
	}
	return (0);
}

