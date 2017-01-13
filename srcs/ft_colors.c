/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:18:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 19:06:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_key_hook_color(int keycode, t_env *fdf)
{
	if (keycode == RED)
		fdf->color.red += 10;
	if (keycode == GREEN)
		fdf->color.green += 10;
	if (keycode == BLUE)
		fdf->color.blue += 10;
}
