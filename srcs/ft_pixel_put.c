/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:06:37 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 14:10:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_env *fdf, int x, int y)
{
	if (x > 0 && y > 0 && x < fdf->win_length && y < fdf->win_width)
	{
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line)] = fdf->color.red;
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line) + 1] = fdf->color.green;
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line) + 2] = fdf->color.blue;
	}
}
