/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 16:57:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_env *fdf)
{
	fdf->point.dx = DX;
	fdf->point.sx = SX;
	fdf->point.dy = DY;
	fdf->point.sy = SY;
	fdf->point.err = ERR;
	while (1)
	{
		if (fdf->mov.l_r + fdf->point.x1 >= 0 && fdf->mov.d_u + fdf->point.y1 >= 0)
			ft_pixel_put(fdf, fdf->mov.l_r + fdf->point.x1, fdf->mov.d_u + fdf->point.y1);
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
