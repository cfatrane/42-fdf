/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/06 14:24:25 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_map(int **map, int nblin, int col)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int k = 50;

	(void)map;
	x = 0;
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "jerome dans le retro");
	while (y < nblin)
	{
		x = 0;
		while (x < col)
		{
			mlx_pixel_put(mlx, win, k + (x * 10),k + (y * 10), 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
