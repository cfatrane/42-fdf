/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:54:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 00:31:54 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_mlx(t_env *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
	printf("padding = %d", fdf->map.pad);
	fdf->mlx_ptr = mlx_init();
	fdf->win_lengh = fdf->map.pad * fdf->map.nbcol * 10;
	fdf->win_width = fdf->map.pad * fdf->map.nblin * 10;
/*	if (fdf->win_lengh > 1000)
		fdf->win_lengh /= 15;
	if (fdf->win_width > 1000)
		fdf->win_width /= 15;
*/	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_lengh, fdf->win_width, "fdf");
//	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
