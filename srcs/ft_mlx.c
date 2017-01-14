/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:54:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 23:29:25 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_mlx(t_env *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
//	fdf->bpp = 24;
//	fdf->size_line = WIN_LENGHT * 3;
//	fdf->endian = 0;

	printf("padding = %d", fdf->map.pad);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "fdf");
//	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,  WIN_LENGHT, WIN_WIDTH);
//	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
