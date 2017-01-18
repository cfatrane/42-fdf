/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 14:12:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == R || keycode == B || keycode == G)
		ft_key_hook_color(keycode, fdf);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
			|| keycode == DOWN_ARROW ||
			keycode == UP_ARROW)
		ft_key_hook_move(keycode, fdf);
	else if (keycode == MORE || keycode == LESS)
		ft_key_hook_alt(keycode, fdf);
	else if (keycode == ONE_NUM_PAD || keycode == TWO_NUM_PAD)
		ft_key_hook_zoom(keycode, fdf);
	else if (keycode == P)
		ft_key_hook_proj(fdf);
	else if (keycode == Z)
		ft_init(fdf);
	ft_expose_hook(fdf);
	return (0);
}

int	ft_expose_hook(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_length, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}
