/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:14:04 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 16:18:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_space(t_env *fdf)
{
	if (fdf->map.nbcol <= 20)
		fdf->point.spc = 25;
	else if (fdf->map.nbcol >= 20 && fdf->map.nbcol <= 50)
		fdf->point.spc = 20;
	else if (fdf->map.nbcol >= 50 && fdf->map.nbcol <= 100)
		fdf->point.spc = 15;
	else if (fdf->map.nbcol >= 100 && fdf->map.nbcol <= 200)
		fdf->point.spc = 5;
	else
		fdf->point.spc = 1;
}

void	ft_window(t_env *fdf)
{
	if (fdf->map.nbcol <= 10)
		fdf->win_length = fdf->map.nbcol * 100;
	else if (fdf->map.nbcol <= 20)
		fdf->win_length = fdf->map.nbcol * 70;
	else if (fdf->map.nbcol >= 20 && fdf->map.nbcol <= 50)
		fdf->win_length = fdf->map.nbcol * 40;
	else if (fdf->map.nbcol >= 50 && fdf->map.nbcol <= 100)
		fdf->win_length = fdf->map.nbcol * 20;
	else if (fdf->map.nbcol >= 100 && fdf->map.nbcol <= 200)
		fdf->win_length = fdf->map.nbcol * 10;
	else
		fdf->win_length = fdf->map.nbcol * 10;
	if (fdf->map.nblin <= 20)
		fdf->win_width = fdf->map.nblin * 100;
	else if (fdf->map.nblin >= 20 && fdf->map.nblin <= 50)
		fdf->win_width = fdf->map.nblin * 40;
	else if (fdf->map.nblin >= 50 && fdf->map.nblin <= 100)
		fdf->win_width = fdf->map.nblin * 20;
	else if (fdf->map.nblin >= 100 && fdf->map.nblin <= 200)
		fdf->win_width = fdf->map.nblin * 10;
	else
		fdf->win_width = fdf->map.nblin * 10;
}

void	ft_init(t_env *fdf)
{
	ft_space(fdf);
	if (!fdf->color.color)
	{
		fdf->color.red = 255;
		fdf->color.green = 255;
		fdf->color.blue = 255;
	}
	fdf->point.cte = fdf->map.pad / 200.00;
	fdf->point.cte1 = 0.5;
	fdf->point.cte2 = 0.5;
	fdf->point.pos = 1;
	fdf->mov.l_r = fdf->win_length / 4;
	fdf->mov.d_u = fdf->win_width / 4;
}
