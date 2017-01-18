/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:54:45 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 16:20:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_mlx(t_env *fdf)
{
	fdf->mlx_ptr = mlx_init();
	ft_window(fdf);
	ft_init(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_length,
			fdf->win_width, "fdf");
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_expose_hook(fdf->win_ptr, ft_expose_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
