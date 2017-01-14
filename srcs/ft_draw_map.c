/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 18:41:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy(t_env *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
}

int	ft_draw_map(t_env *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
	fdf->bpp = 24;
	fdf->size_line = 2000;
	fdf->endian = 0;
	fdf->color.color = fdf->color.red * 65536 + fdf->color.green * 256 + fdf->color.blue;

	fdf->mlx_ptr = mlx_init();

	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "fdf");

	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,  500, 500);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);

	//	mlx_mouse_hook (fdf->win_ptr, int (*funct_ptr)(), void *param );
	//	mlx_hook(fdf->win_ptr, 17, 1L << 17, destroy, fdf);
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_key_hook(fdf->win_ptr, key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
