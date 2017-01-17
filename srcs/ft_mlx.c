/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:54:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 17:34:43 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_env *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
	fdf->point.cte = 0.5;
	fdf->point.cte1 = 0.5;
	fdf->point.cte2 = 0.5;
	fdf->point.pos = 10;
	fdf->point.spc = 20;
}

int	ft_mlx(t_env *fdf)
{
	printf("padding = %d", fdf->map.pad);
	fdf->mlx_ptr = mlx_init();
	ft_init(fdf);
//	fdf->win_lengh = fdf->map.nbcol % 1280;
//	fdf->win_width = fdf->map.nblin % 720;
	fdf->win_lengh = 1280;
	fdf->win_width = 720;
//	fdf->point.pos = -15;
/*	if (fdf->win_lengh > 1000)
		fdf->win_lengh /= 15;
	if (fdf->win_width > 1000)
		fdf->win_width /= 15;
*/	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_lengh, fdf->win_width, "fdf");
//	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, ft_expose_hook, fdf);
//	mlx_expose_hook(fdf->win_ptr, ft_expose_hook_iso, fdf);
//	mlx_key_hook(fdf->win_ptr, ft_key_hook_iso, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
