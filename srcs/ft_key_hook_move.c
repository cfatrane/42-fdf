/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:00:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 21:01:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_move(int keycode, t_env *fdf)
{
	if (keycode == RIGHT_ARROW)
		fdf->point.mv_l_r += 15;
	else if (keycode == LEFT_ARROW)
		fdf->point.mv_l_r -= 15;
	else if (keycode == DOWN_ARROW)
		fdf->point.mv_d_u += 15;
	else if (keycode == UP_ARROW)
		fdf->point.mv_d_u -= 15;
}
