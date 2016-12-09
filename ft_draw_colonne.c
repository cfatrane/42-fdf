/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_colonne.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:37:19 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 17:37:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_draw_colonne(int **map, int nblin, int nbcol, void *mlx, void *win)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int y;

	y1 = 0;
	while (y1 < (nblin - 1) * 20)
	{
		x1 = 0;
		while (x1 < nbcol * 20)
		{
			x2 = x1;
			y2 = y1 + 20;
			y = y1;
			while (y <= y2)
			{
				mlx_pixel_put(mlx, win, 10 + ((x1 + ((x2 - x1) * (y - y1)) / (y2 - y1))), 10 + y, 0x00FFFFFF);
				y++;
			}
			x1 = x1 + 20;
		}
		y1 = y1 + 20;
	}
	return (0);
}

