/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 16:01:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
/*	else if(keycode == 35)
		mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
*/	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *fdf)
{



	return (0);
}

int	expose_hook(t_env *fdf)
{
//	ft_draw_paral_collumns(fdf);
//	ft_draw_paral_lines(fdf);
	ft_draw_iso_collumns(fdf);
	ft_draw_iso_lines(fdf);

	return (0);
}
