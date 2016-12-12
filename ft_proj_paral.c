/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_paral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:50 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/12 16:33:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double cte = 7;
double cte1 = 1;
double cte2 = 1;
int pos = 10;

int	ft_draw_parall_single_col(t_coord *point, t_env *fdf, int line, int col)
{
	while (point->y < ((fdf->nblin - 1) * 20))
	{
		point->x2 = point->x + (cte * (pos * fdf->map[line + 1][col]));
		point->y2 = (point->y + 20) + ((cte / 2) * (pos * fdf->map[line + 1][col]));
		ft_draw_line(point, fdf);
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
		point.x1 = point.x + (cte * (pos * fdf->map[line][col]));
		point.y1 = point.y + ((cte / 2) * (pos * fdf->map[line][col]));
		ft_draw_parall_single_col(&point, fdf, line, col);
		col++;
		point.x += 20;
	}
	return (0);
}

int	ft_draw_parall_single_line(t_coord *point, t_env *fdf, int line, int col)
{
	while (point->x < (fdf->nbcol - 1) * 20)
	{
		point->x2 = (point->x + 20) + (cte * (pos * fdf->map[line][col + 1]));
		point->y2 = point->y + ((cte / 2) * (pos * fdf->map[line][col + 1]));
		ft_draw_line(point, fdf);
		col++;
		point->x += 20;
		point->x1 = point->x2;
		point->y1 = point->y2;
	}
	return (0);
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
		point.x1 = point.x + (cte * (pos * fdf->map[line][col]));
		point.y1 = point.y + ((cte / 2) * (pos * fdf->map[line][col]));
		ft_draw_parall_single_line(&point, fdf, line,col);
		line++;
		point.y += 20;
	}
	return (0);
}
