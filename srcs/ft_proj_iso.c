/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 17:37:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_single_collumn(t_env *fdf)
{
	while (fdf->point.y < ((fdf->map.nblin - 1) * fdf->point.spc))
	{
		fdf->point.x2 = X2IC;
		fdf->point.y2 = Y2IC;
		ft_bresenham(fdf);
		fdf->map.y++;
		fdf->point.y += fdf->point.spc;
		fdf->point.x1 = fdf->point.x2;
		fdf->point.y1 = fdf->point.y2;
	}
}

void	ft_draw_iso_collumns(t_env *fdf)
{
	fdf->map.x = 0;
	fdf->point.x = 0;
	while (fdf->point.x < fdf->map.nbcol * fdf->point.spc)
	{
		fdf->point.y = 0;
		fdf->map.y = 0;
		fdf->point.x1 = X1IC;
		fdf->point.y1 = Y1IC;
		ft_draw_single_collumn(fdf);
		fdf->map.x++;
		fdf->point.x += fdf->point.spc;
	}
}
void	ft_draw_iso_single_line(t_env *fdf)
{
	while (fdf->point.x < (fdf->map.nbcol - 1) * fdf->point.spc)
	{
		fdf->point.x2 = X2IL;
		fdf->point.y2 = Y2IL;
		ft_bresenham(fdf);
		fdf->map.x++;
		fdf->point.x += fdf->point.spc;
		fdf->point.x1 = fdf->point.x2;
		fdf->point.y1 = fdf->point.y2;
	}
}

void	ft_draw_iso_lines(t_env *fdf)
{
	fdf->map.y = 0;
	fdf->point.y = 0;
	while (fdf->point.y < fdf->map.nblin * fdf->point.spc)
	{
		fdf->map.x = 0;
		fdf->point.x = 0;
		fdf->point.x1 = X1IL;
		fdf->point.y1 = Y1IL;
		ft_draw_iso_single_line(fdf);
		fdf->map.x++;
		fdf->map.y++;
		fdf->point.y += fdf->point.spc;
	}
}
