/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:00:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 20:01:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_move(int keycode, t_env *fdf)
{
	if (keycode == RIGHT_ARROW)
		fdf->mov.l_r += 20;
	if (keycode == LEFT_ARROW)
		fdf->mov.l_r -= 20;
	if (keycode == DOWN_ARROW)
		fdf->mov.d_u += 20;
	if (keycode == UP_ARROW)
		fdf->mov.d_u -= 20;
}
