/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_paral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:50 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 15:41:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 2;
int pos = 30;

int	ft_draw_parall_collumns(t_env *fdf)
{
	int		col;
	int		line;

	col = 0;
	fdf->point.x = 0;
	while (fdf->point.x < fdf->nbcol * 20)
	{
		fdf->point.y = 0;
		line = 0;
		fdf->point.x1 = fdf->point.x + (cte * (pos * fdf->map.map[line][col]));
		fdf->point.y1 = fdf->point.y + ((cte / 2) * (pos * fdf->map.map[line][col]));
		while (fdf->point.y < ((fdf->nblin - 1) * 20))
		{
			fdf->point.x2 = fdf->point.x + (cte * (pos * fdf->map.map[line + 1][col]));
			fdf->point.y2 = (fdf->point.y + 20) + ((cte / 2) * (pos * fdf->map.map[line + 1][col]));
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