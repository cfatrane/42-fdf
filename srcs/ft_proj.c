/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:11:42 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 17:39:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_proj(t_env *fdf)
{
	ft_draw_collumns(fdf);
	ft_draw_lines(fdf);
	//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
}
