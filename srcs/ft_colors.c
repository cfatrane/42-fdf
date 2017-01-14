/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:18:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 12:55:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_key_hook_color(int keycode, t_env *fdf)
{
	fdf->color.color = fdf->color.red * 65536 + fdf->color.green * 256 + fdf->color.blue;
	if (keycode == R)
		fdf->color.red += 10;
	if (keycode == G)
		fdf->color.green += 10;
	if (keycode == B)
		fdf->color.blue += 10;
}
