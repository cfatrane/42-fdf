/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 18:08:14 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_parall_col(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;
	int y;
	int col;
	int line;
	double cte = 5;
	int k = 50;

	line = 0;
	x = 0;
	while (x < nbcol * 20)
	{
		y = 0;
		line = 0;
		x1 = x + (cte * (15 * map[line][col]));
		y1 = y + ((cte / 2) * (15 * map[line][col]));
		while (y < ((nblin - 1) * 20))
		{
			x2 = x + (cte * (15 * map[line + 1][col]));
			y2 = (y + 20) + ((cte / 2) * (15 * map[line + 1][col]));
/*			printf("x1 vaut = %d\n", X1);
			printf("y1 vaut = %d\n", Y1);
			printf("x2 vaut = %d\n", X2);
			printf("y2 vaut = %d\n", Y2);*/
			ft_draw_cas_trois_quatre(x1, y1, x2, y2, mlx, win);
//			printf("--------------\n");
			line++;
			y = y + 20;
			x1 = x2;
			y1 = y2;
		}
/*		printf("-----------------------------------\n");
		printf("NEW COLLUMN NEW COLLUMN NEW COLLUMN\n");
		printf("-----------------------------------\n");*/
		col++;
		x = x + 20;
	}
	return (0);
}

int	ft_draw_parall_line(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;
	int y;
	int col;
	int line;
	double cte = 5;
	int k = 50;

	line = 0;
	y = 0;
	while (y < nblin * 20) // OK
	{
		col = 0;
		x = 0;
		x1 = x + (cte * (15 * map[line][col]));
		y1 = y + ((cte / 2) * (15 * map[line][col]));
		while (x < (nbcol - 1 ) * 20) // OK
		{
			x2 = (x + 20) + (cte * (15 * map[line][col + 1]));
			y2 = y + ((cte / 2) * (15 * map[line][col + 1]));
			printf("x1 vaut = %d\n", x1);
			printf("y1 vaut = %d\n", y1);
			printf("x2 vaut = %d\n", x2);
			printf("y2 vaut = %d\n", y2);
			if (x1 < x2)
				ft_draw_cas_un_deux(x1,y1, x2, y2, mlx, win);
			else if (x1 > x2)
				ft_draw_cas_trois_quatre(x1, y1, x2, y2, mlx, win);
			printf("--------------\n");
			col++;
			x = x + 20;
			x1 = x2;
			y1 = y2;
		}
		printf("--------------------------\n");
		printf("NEW LINE NEW LINE NEW LINE\n");
		printf("--------------------------\n");
		line++;
		y = y + 20; // OK
	}
	return (0);
}

int	ft_draw_map(int **map, int nblin, int nbcol)
{
	void	*mlx;
	void	*win;

	(void)map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 1500, "fdf");
	ft_draw_parall_line(map, nblin, nbcol, mlx, win);
//	ft_draw_parall_col(map, nblin, nbcol, mlx, win);
	mlx_loop(mlx);
	return (0);
}
