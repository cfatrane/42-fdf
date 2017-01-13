/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:32:44 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 16:07:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy(t_env *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
}

int	ft_draw_map(t_env *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->nblin * 100, fdf->nbcol * 100, "fdf");
	mlx_key_hook(fdf->win_ptr, key_hook, fdf);
//	mlx_mouse_hook (fdf->win_ptr, int (*funct_ptr)(), void *param );
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	mlx_hook(fdf->win_ptr, 17, 1L << 17, destroy, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
