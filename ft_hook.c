/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:55 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 16:18:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *fdf)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env fdf)
{



	return (0);
}
/*
int	expose_hook(t_env *fdf)
{



}
*/
