/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:37:12 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/01 16:17:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int	my_key_func(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "jerome dans le retro");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_func, 0);
	mlx_loop(mlx);
}
