/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 18:45:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == R || keycode == B || keycode == G)
		ft_mlx_key_hook_color(keycode, fdf);
	else if (keycode == MORE)
		fdf->point.cte += 0.1;
	else if (keycode == LESS)
		fdf->point.cte -= 0.1;
	else if (keycode == P)
		fdf->point.pos += 15;
	printf("keycode = %d\n", keycode);
	printf("color = %#X\n", fdf->color.color);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	expose_hook(fdf);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *fdf)
{



	return (0);
}

int	expose_hook(t_env *fdf)
{
	ft_draw_paral_collumns(fdf);
	ft_draw_paral_lines(fdf);
//	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	//	ft_draw_iso_collumns(fdf);
	//	ft_draw_iso_lines(fdf);
	return (0);
}
