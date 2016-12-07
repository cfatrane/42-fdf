/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/07 13:41:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	ft_draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x1;
	int k = 50;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, k + x , k + ((y1 + ((y2 - y1) * (x - x1))/(x2 - x1))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_colonne(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int x;

	x = x1;
	int k = 50;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, k + x , k + ((y1 + ((y2 - y1) * (x - x1))/(x2 - x1))), 0x00FF0000);
		x++;
	}
	return (0);
}

int	ft_draw_map(int **map, int nblin, int nbcol)
{
	void	*mlx;
	void	*win;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
//	int k = 50;

	(void)map;
	x1 = 0;
	y1 = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "jerome dans le retro");
//	ft_draw_line(x, y, x2, y2, mlx, win);


	while (y1 <= nblin * 15)
	{
		x1 = 0;
		y2 = y1;
		while (x1 < nbcol * 15)
		{
			x2 = x1 + 15;
			printf("x1 = %d\n", x1);
			printf("y1 = %d\n", y1);
			printf("x2 = %d\n", x2);
			printf("y2 = %d\n", y2);
			ft_draw_line(x1, y1, x2, y2, mlx, win);
		//	mlx_pixel_put(mlx, win, k + (x * 20),k + (y * 20), 0x00FF0000);
			x1 = x1 + 15;
		}
		y1 = y1 + 15;
	}
	mlx_loop(mlx);
	return (0);
}
