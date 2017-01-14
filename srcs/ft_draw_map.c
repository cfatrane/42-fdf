/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 20:45:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_map(t_env *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
	fdf->bpp = 24;
	fdf->size_line = WIN_LENGHT * 3;
	fdf->endian = 0;


	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "fdf");
//	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,  WIN_LENGHT, WIN_WIDTH);
//	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
