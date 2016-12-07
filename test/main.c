/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:37:12 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/07 10:53:01 by cfatrane         ###   ########.fr       */
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

int	my_key_func(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int x1 = 25;
	int y1 = 25;
	int x2 = 150;
	int y2 = 25;
	int x = x1;
	int k = 50;

//	int avc = ((360)/(8 * R));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "jerome dans le retro");

	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, (k + x), (y1 + ((y2 - y1) * (x - x1))/(x2 - x1)), 0x00FF0000);
		x++;
	}
/*	while (avc < 360)
	{
		avc++;
	}*/
//	mlx_key_hook(win, my_key_func, 0);
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
