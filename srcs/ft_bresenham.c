/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 00:29:44 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_env *fdf)
{
	fdf->point.dx = abs(fdf->point.x2 - fdf->point.x1);
	fdf->point.sx = fdf->point.x1 < fdf->point.x2 ? 1 : -1;
	fdf->point.dy = abs(fdf->point.y2 - fdf->point.y1);
	fdf->point.sy = fdf->point.y1 < fdf->point.y2 ? 1 : -1;
	fdf->point.err = (fdf->point.dx > fdf->point.dy ? fdf->point.dx : -fdf->point.dy) / 2;
	while (1)
	{
		ft_pixel_put(fdf, ((fdf->win_lengh / 2) / 3) + fdf->point.mv_l_r + fdf->point.x1, ((fdf->win_width / 3)) + fdf->point.mv_d_u + fdf->point.y1);
		if (fdf->point.x1 == fdf->point.x2 && fdf->point.y1 == fdf->point.y2)
			break ;
		fdf->point.e2 = fdf->point.err;
		if (fdf->point.e2 > -fdf->point.dx)
		{
			fdf->point.err -= fdf->point.dy;
			fdf->point.x1 += fdf->point.sx;
		}
		if (fdf->point.e2 < fdf->point.dy)
		{
			fdf->point.err += fdf->point.dx;
			fdf->point.y1 += fdf->point.sy;
		}
	}
}
