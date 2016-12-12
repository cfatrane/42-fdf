/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/12 14:33:24 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_draw_map(t_env *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_LENGHT, WIN_WIDTH, "fdf");
	mlx_key_hook(fdf->win_ptr, key_hook, fdf);
//	mlx_mouse_hook (fdf->win_ptr, int (*funct_ptr)(), void *param );
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
