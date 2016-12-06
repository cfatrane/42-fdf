/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:37:12 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/06 15:06:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

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
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
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
