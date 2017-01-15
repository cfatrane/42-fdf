/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:56:51 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/15 17:45:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_color(int keycode, t_env *fdf)
{
	if (keycode == R)
		fdf->color.red += 10;
	if (keycode == G)
		fdf->color.green += 10;
	if (keycode == B)
		fdf->color.blue += 10;
}
