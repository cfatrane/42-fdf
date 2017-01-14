/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_paral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:58:50 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 18:44:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int pos_paral = 50;

int	ft_draw_paral_collumns(t_env *fdf)
{
	int		col;
	int		line;

	col = 0;
	fdf->point.x = 0;
	while (fdf->point.x < fdf->nbcol * 20)
	{
		fdf->point.y = 0;
		line = 0;
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (pos_paral * fdf->map.map[line][col]));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) * (pos_paral * fdf->map.map[line][col]));
		while (fdf->point.y < ((fdf->nblin - 1) * 20))
		{
			fdf->point.x2 = fdf->point.x + (fdf->point.cte * (pos_paral * fdf->map.map[line + 1][col]));
			fdf->point.y2 = (fdf->point.y + 20) + ((fdf->point.cte / 2) * (pos_paral * fdf->map.map[line + 1][col]));
			ft_bresenham(fdf);
			mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
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

int		ft_draw_paral_lines(t_env *fdf)
{
	int		col;
	int		line;

	line = 0;
	fdf->point.y = 0;
	while (fdf->point.y < fdf->nblin * 20)
	{
		col = 0;
		fdf->point.x = 0;
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (pos_paral * fdf->map.map[line][col]));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) * (pos_paral * fdf->map.map[line][col]));
		while (fdf->point.x < (fdf->nbcol - 1) * 20)
		{
			fdf->point.x2 = (fdf->point.x + 20) + (fdf->point.cte * (pos_paral * fdf->map.map[line][col + 1]));
			fdf->point.y2 = fdf->point.y + ((fdf->point.cte / 2) * (pos_paral * fdf->map.map[line][col + 1]));
			ft_bresenham(fdf);
			mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
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
