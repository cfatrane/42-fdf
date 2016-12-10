/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/10 16:31:43 by cfatrane         ###   ########.fr       */
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


typedef struct	s_point
{
	int	abscisse;
	int	ordonnée;
	int	altitude;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		nblin;
	int		nbcol;
	int x1;
	int y1;
	int x2;
	int y2;
}				t_env;

int		ft_fdf(char *argv);
int		ft_create_map(char *argv);
int		ft_draw_map(int **map, t_env *fdf);
int		ft_draw_line(int x1, int y1, int x2, int y2, t_env *fdf);
int		key_hook(int keycode, t_env *fdf);
int		mouse_hook(int button, int x, int y, t_env fdf);
int		expose_hook(t_env *fdf);

#endif
