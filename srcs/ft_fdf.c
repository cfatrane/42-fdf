/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:17:59 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 12:48:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_fdf(char *argv)
{
	t_env	fdf;
	int x = 0, y = 0;

	ft_bzero(&fdf, sizeof(t_env));
	//	ft_check(argv); PARSER OKLM
	ft_create_map(argv, &fdf);
/*	while(y < fdf.map.y)
	{
		x = 0;
		while (x < fdf.map.x)
		{
			printf("%d ", fdf.map.map[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
*/	ft_draw_map(&fdf); // Dessiner map avec algo de Bresenham
	free(*(fdf.map.map));
	return (0);
}
