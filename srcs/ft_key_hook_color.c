/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:56:51 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 14:00:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_color(int keycode, t_env *fdf)
{
	if (keycode == R)
		fdf->color.red -= 20;
	if (keycode == G)
		fdf->color.green -= 20;
	if (keycode == B)
		fdf->color.blue -= 20;
}
