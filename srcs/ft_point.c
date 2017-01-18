/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:38:40 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 15:37:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_point_collumn_x_one(t_env *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z1PC));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.pad * Z1PC));
	}
	else
	{
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			fdf->point.y;
		fdf->point.y1 = ((fdf->point.pos * Z1IC) + (fdf->point.cte1 / 2) *
				fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y);
	}
}

void	ft_point_collumn_x_two(t_env *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x2 = fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z2PC));
		fdf->point.y2 = (fdf->point.y + fdf->point.spc) +
			((fdf->point.cte / 2) * (fdf->map.pad * Z2PC));
	}
	else
	{
		fdf->point.x2 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			(fdf->point.y + fdf->point.spc);
		fdf->point.y2 = (fdf->point.pos * Z2IC) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) *
			(fdf->point.y + fdf->point.spc);
	}
}

void	ft_point_line_x_one(t_env *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z1PL));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.pad * Z1PL));
	}
	else
	{
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			fdf->point.y;
		fdf->point.y1 = (fdf->point.pos * Z1IL) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y;
	}
}

void	ft_point_line_x_two(t_env *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x2 = (fdf->point.x + fdf->point.spc) + (fdf->point.cte *
				(fdf->map.pad * Z2PL));
		fdf->point.y2 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.pad * Z2PL));
	}
	else
	{
		fdf->point.x2 = fdf->point.cte1 * (fdf->point.x + fdf->point.spc) -
			fdf->point.cte2 * fdf->point.y;
		fdf->point.y2 = (fdf->point.pos * Z2IL) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) *
			(fdf->point.y + fdf->point.spc);
	}
}
