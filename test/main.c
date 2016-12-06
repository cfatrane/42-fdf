/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:37:12 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/06 18:23:37 by cfatrane         ###   ########.fr       */
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
	int x0 = 250;
	int y0 = 250;
	int a = 0;
	int R = 200;

	int avc = ((360)/(8 * R));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "jerome dans le retro");

		mlx_string_put(mlx, win, x0, y0, 0xFF0000, "JEROME DANS LE METRO");
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
