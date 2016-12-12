/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_paral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/12 15:59:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 7;
double cte1 = 1;
double cte2 = 1;
int pos = 10;

int	ft_draw_parall_col(t_env *fdf)
{
	t_coord	point;
	int		x;
	int		y;
	int		col;
	int		line;

	col = 0;
	x = 0;
	while (x < fdf->nbcol * 20)
	{
		y = 0;
		line = 0;
		point.x1 = x + (cte * (pos * fdf->map[line][col]));
		point.y1 = y + ((cte / 2) * (pos * fdf->map[line][col]));
		while (y < ((fdf->nblin - 1) * 20))
		{
			point.x2 = x + (cte * (pos * fdf->map[line + 1][col]));
			point.y2 = (y + 20) + ((cte / 2) * (pos * fdf->map[line + 1][col]));
			ft_draw_line(&point, fdf);
			line++;
			y += 20;
			point.x1 = point.x2;
			point.y1 = point.y2;
		}
		col++;
		x += 20;
	}
	return (0);
}

int	ft_draw_parall_line(t_env *fdf)
{
	t_coord	point;
	int		x;
	int		y;
	int		col;
	int		line;

	line = 0;
	y = 0;
	while (y < fdf->nblin * 20)
	{
		col = 0;
		x = 0;
		point.x1 = x + (cte * (pos * fdf->map[line][col]));
		point.y1 = y + ((cte / 2) * (pos * fdf->map[line][col]));
		while (x < (fdf->nbcol - 1) * 20)
		{
			point.x2 = (x + 20) + (cte * (pos * fdf->map[line][col + 1]));
			point.y2 = y + ((cte / 2) * (pos * fdf->map[line][col + 1]));
			ft_draw_line(&point, fdf);
			col++;
			x += 20;
			point.x1 = point.x2;
			point.y1 = point.y2;
		}
		line++;
		y += 20;
	}
	return (0);
}
