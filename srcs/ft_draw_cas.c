/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:34:31 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/02 13:45:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int k = 20;

int	ft_draw_cas_un_deux(t_coord *point, t_env *fdf)
{
	int x;

	x = point->x1;
	while (x <= point->x2)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, k + x, k + ((point->y1 + ((point->y2 - point->y1) * (x - point->x1)) / (point->x2 - point->x1))), 0x00FFFFFF);
		x++;
	}
	return (0);
}

int	ft_draw_cas_trois_quatre(t_coord *point, t_env *fdf)
{
	int x;

	x = point->x2;
	while (x <= point->x1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, k + x, k + ((point->y2 + ((point->y1 - point->y2) * (x - point->x2)) / (point->x1 - point->x2))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_cas_cinq_six(t_coord *point, t_env *fdf)
{
	int x;

	x = point->y1;
	while (x <= point->y2)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, k + ((point->x1 + ((point->x2 - point->x1) * (x - point->y1)) / (point->y2 - point->y1))), k + x, 0x0000FF00);
		x++;
	}
	return (0);
}

int	ft_draw_cas_sept_huit(t_coord *point, t_env *fdf)
{
	int x;

	x = point->y2;
	while (x <= point->y1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, k + ((point->x2 + ((point->x1 - point->x2) * (x - point->y2)) / (point->y1 - point->y2))), k + x, 0x000000FF);
		x++;
	}
	return (0);
}

int	ft_draw_line(t_coord *point, t_env *fdf)
{
	if (point->x1 < point->x2)
		ft_draw_cas_un_deux(point, fdf);
	else if (point->x1 > point->x2)
		ft_draw_cas_trois_quatre(point, fdf);
	else if (point->y1 < point->y2)
		ft_draw_cas_cinq_six(point, fdf);
	else if (point->y1 > point->y2)
		ft_draw_cas_sept_huit(point, fdf);
	return (0);
}
