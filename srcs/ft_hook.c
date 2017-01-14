/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 00:31:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == R || keycode == B || keycode == G)
		ft_key_hook_color(keycode, fdf);
	else if (keycode == MORE)
		fdf->point.cte += 0.1;
	else if (keycode == LESS)
		fdf->point.cte -= 0.1;
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW || keycode == DOWN_ARROW ||
			keycode == UP_ARROW)
		ft_key_hook_move(keycode, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	expose_hook(fdf);
//	printf("keycode = %d\n", keycode);
//	printf("color = %#X\n", fdf->color.color);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *fdf)
{



	return (0);
}

int	expose_hook(t_env *fdf)
{
	ft_proj(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	//	ft_draw_iso_collumns(fdf);
	//	ft_draw_iso_lines(fdf);
	return (0);
}
