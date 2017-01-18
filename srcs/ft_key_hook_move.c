/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:00:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 14:03:38 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_move(int keycode, t_env *fdf)
{
	if (keycode == RIGHT_ARROW)
		fdf->mov.l_r += 40;
	if (keycode == LEFT_ARROW)
		fdf->mov.l_r -= 40;
	if (keycode == DOWN_ARROW)
		fdf->mov.d_u += 40;
	if (keycode == UP_ARROW)
		fdf->mov.d_u -= 40;
}

void	ft_key_hook_alt(int keycode, t_env *fdf)
{
	if (keycode == MORE)
	{
		fdf->point.cte += 0.3;
		fdf->point.pos += 5;
	}
	else if (keycode == LESS)
	{
		fdf->point.cte -= 0.3;
		fdf->point.pos -= 5;
	}
}

void	ft_key_hook_zoom(int keycode, t_env *fdf)
{
	if (keycode == ONE_NUM_PAD)
	{
		fdf->point.spc -= 5;
		if (fdf->point.spc <= 0)
			fdf->point.spc += 5;
	}
	else if (keycode == TWO_NUM_PAD)
		fdf->point.spc += 5;
}

void	ft_key_hook_proj(t_env *fdf)
{
	if (fdf->proj == 0)
		fdf->proj = 1;
	else if (fdf->proj == 1)
		fdf->proj = 0;
}
