/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 20:20:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook_paral(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == R || keycode == B || keycode == G)
		ft_key_hook_color(keycode, fdf);
	else if (keycode == MORE)
	{
		fdf->point.cte += 0.1;
		fdf->point.cte1 += 0.1;
		fdf->point.cte2 += 0.1;
	}
	else if (keycode == LESS)
	{
		fdf->point.cte -= 0.1;
		fdf->point.cte1 -= 0.1;
		fdf->point.cte2 -= 0.1;
	}
	else if (keycode == A)
		fdf->point.pos += 5;
	else if (keycode == Q)
		fdf->point.pos -= 5;
	//		else if (keycode == ARROW)
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW || keycode == DOWN_ARROW ||
			keycode == UP_ARROW)
		ft_key_hook_move(keycode, fdf);
	else if (keycode == ONE_NUM_PAD)
	{
		if (fdf->point.spc <= 0)
			ft_abs(fdf->point.spc);
		fdf->point.spc -= 5;
	}
	else if (keycode == TWO_NUM_PAD)
		fdf->point.spc += 5;
	printf("keycode = %d pos = %d\n", keycode, fdf->point.pos);
	ft_expose_hook_paral(fdf);
	//	ft_expose_hook_iso(fdf);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_env *fdf)
{



	return (0);
}

int	ft_expose_hook_iso(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,fdf->win_lengh, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	ft_draw_iso_collumns(fdf);
	//	ft_draw_iso_lines(fdf);
	mlx_put_image_to_window (fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}

int	ft_expose_hook_paral(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,fdf->win_lengh, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	ft_draw_paral_collumns(fdf);
	ft_draw_paral_lines(fdf);
	mlx_put_image_to_window (fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}
