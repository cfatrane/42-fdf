/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:11:42 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 00:02:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_proj(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,fdf->win_lengh, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
	ft_draw_paral_collumns(fdf);
	ft_draw_paral_lines(fdf);
	mlx_put_image_to_window (fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
}
