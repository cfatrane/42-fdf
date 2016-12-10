/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:34:31 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 14:05:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int k = 200;

int	ft_draw_cas_un_deux(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, k + x, k + ((y1 + ((y2 - y1) * (x - x1)) / (x2 - x1))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_cas_trois_quatre(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x2;
	while (x <= x1)
	{
		mlx_pixel_put(mlx, win, k + x, k + ((y2 + ((y1 - y2) * (x - x2)) / (x1 - x2))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_cas_cinq_six(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = y1;
	while (x <= y2)
	{
		mlx_pixel_put(mlx, win, k + ((x1 + ((x2 - x1) * (x - y1)) / (y2 - y1))), k + x, 0x0000FF00);
		x++;
	}
	return (0);
}

int	ft_draw_cas_sept_huit(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = y2;
	while (x <= y1)
	{
		mlx_pixel_put(mlx, win, k + ((x2 + ((x1 - x2) * (x - y2)) / (y1 - y2))), k + x, 0x0000FF00);
		x++;
	}
	return (0);
}

int	ft_draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	if (x1 < x2)
		ft_draw_cas_un_deux(x1,y1, x2, y2, mlx, win);
	else if (x1 > x2)
		ft_draw_cas_trois_quatre(x1, y1, x2, y2, mlx, win);
	else if (y1 < y2)
		ft_draw_cas_cinq_six(x1, y1, x2, y2, mlx, win);
	else if (y1 > y2)
		ft_draw_cas_sept_huit(x1, y1, x2, y2, mlx, win);
	return (0);
}

