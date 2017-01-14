/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 18:40:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_env *fdf)
{
	int err;
	int e2;

	fdf->point.dx = abs(fdf->point.x2 - fdf->point.x1);
	fdf->point.sx = fdf->point.x1 < fdf->point.x2 ? 1 : -1;
	fdf->point.dy = abs(fdf->point.y2 - fdf->point.y1);
	fdf->point.sy = fdf->point.y1 < fdf->point.y2 ? 1 : -1;
	err = (fdf->point.dx > fdf->point.dy ? fdf->point.dx : -fdf->point.dy) / 2;
	while (1)
	{
		ft_pixel_put(fdf, fdf->point.x1, fdf->point.y1);
		//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->point.pos + fdf->point.x1, fdf->point.pos + fdf->point.y1, fdf->color.color);
		if (fdf->point.x1 == fdf->point.x2 && fdf->point.y1 == fdf->point.y2)
			break ;
		e2 = err;
		if (e2 > -fdf->point.dx)
		{
			err -= fdf->point.dy;
			fdf->point.x1 += fdf->point.sx;
		}
		if (e2 < fdf->point.dy)
		{
			err += fdf->point.dx;
			fdf->point.y1 += fdf->point.sy;
		}
	}
}
