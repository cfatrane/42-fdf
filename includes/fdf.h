/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/09 18:37:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

int		ft_fdf(char *argv);
int		ft_create_map(char *argv);
int		ft_draw_map(int **map, int nblin, int nbcol);
int		ft_draw_cas_un_deux(int x1, int y1, int x2, int y2, void *mlx, void *win);
int		ft_draw_cas_trois_quatre(int x1, int y1, int x2, int y2, void *mlx, void *win);
int		ft_draw_cas_cinq_six(int x1, int y1, int x2, int y2, void *mlx, void *win);
int		ft_draw_cas_sept_huit(int x1, int y1, int x2, int y2, void *mlx, void *win);

typedef struct	s_point
{
	int abscisse;
	int ordonnée;
	int altitude;
}				t_point;

typedef struct	s_draw
{
	int x1;
	int y1;
	int x2;
	int y2;
}				t_draw;

#endif
