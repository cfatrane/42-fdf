/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 14:36:56 by cfatrane         ###   ########.fr       */
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

# define WIN_LENGHT 1500
# define WIN_WIDTH 1500
# define ESC 53

typedef struct	s_map
{
	int		**map;
	int		x;
	int		y;
	int		color;
}				t_map;

typedef struct	s_point
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_point;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	struct s_map	map;
	struct s_point	point;
//	int		**map;
	int		nblin;
	int		nbcol;
	int		win_lengh;
	int		win_width;
}				t_env;

int		ft_fdf(char *argv);
int		ft_create_map(char *argv, t_env *fdf);
int		ft_draw_map(t_env *fdf);
//int		ft_draw_line(t_coord *point, t_env *fdf);
int		key_hook(int keycode, t_env *fdf);
int		mouse_hook(int button, int x, int y, t_env *fdf);
int		expose_hook(t_env *fdf);
int		ft_draw_parall_lines(t_env *fdf);
int		ft_draw_parall_collumns(t_env *fdf);

#endif
