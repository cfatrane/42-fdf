/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:37:12 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 16:08:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

int	my_key_func(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	printf("key event %d\n", keycode);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int x1 = 400;
	int y1 = 400;
	int x2 = 200;
	int y2 = 200;
	//	int x = x1;
	int k = 50;

	//	int avc = ((360)/(8 * R));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "jerome dans le retro");

/*	int X1 = x1 + 0.5 * 0;
	int Y1 = y1 + (0.5/2) * 0;
	int X2 = x2 + 0.5 * 20;
	int Y2 = y2 + (0.5/2) * 20;*/
	int x = x2;
//	x = x1;
	mlx_string_put(mlx, win, 50 + x1, 50 + y1, 0x00FF0000, "Debut");
	mlx_string_put(mlx, win, 50 + x2, 50 + y2, 0x00FF0000, "Fin");
	while (x <= x1)
	{
		mlx_pixel_put(mlx, win, 50 + x, 50 + ((y2 + ((y1 - y2) * (x - x2)) / (x1 - x2))), 0x00FF0000);
		x++;
	}
/*	while (x <= X1)
	{
		mlx_pixel_put(mlx, win, (k + x), (y1 + ((Y1 - y1) * (x - x1))/(X1 - x1)), 0x00FF0000);
		x++;
	}*/
	/*	while (avc < 360)
		{
		avc++;
		}*/
		mlx_key_hook(win, my_key_func, 0);
	mlx_loop(mlx);
	while (5);
}

/*
   int	main(int argc, char **argv)
   {
   int fd;

   fd = (open(argv[1], O_RDONLY));
   if (argc != 2)
   {
   printf ("Error opening file unexist.ent: %s\n",strerror(errno));
   perror("Usage :");
   }
   else if (!argv[1])
   perror("No file argv[1]");
   }*/
