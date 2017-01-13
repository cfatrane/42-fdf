/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 19:13:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
/*	if (keycode == RED)
		fdf->color.red += 20;
	if (keycode == GREEN)
		fdf->color.green += 20;
	if (keycode == BLUE)
		fdf->color.blue += 20;*/
	else if (keycode == RED || keycode == BLUE || keycode == GREEN)
		ft_mlx_key_hook_color(keycode, fdf);
	else if (keycode == CTE)
		fdf->point.cte += 0.1;
	else if (keycode == CTE && keycode == LESS)
		fdf->point.cte -= 0.1;
	printf("keycode = %d\n", keycode);
	printf("color = %#X\n", fdf->color.color);
	fdf->color.color = fdf->color.red * 65536 + fdf->color.green * 256 + fdf->color.blue;
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
	//	ft_draw_iso_collumns(fdf);
	//	ft_draw_iso_lines(fdf);

	return (0);
}
