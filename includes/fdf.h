/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/13 19:12:26 by cfatrane         ###   ########.fr       */
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
# define LESS 78
// White RGB code = 255*65536+255*256+255 = #FFFFFF

# define WHITE 0xFFFFFF
# define RED 15
# define GREEN 9
# define BLUE 11

# define CTE 8
/*
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x008000
*/
typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				color;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	double			cte;
}					t_point;

typedef struct		s_color
{
	int				color;
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				nblin;
	int				nbcol;
	int				win_lengh;
	int				win_width;
	struct s_color	color;
	struct s_map	map;
	struct s_point	point;
}					t_env;

int					ft_fdf(char *argv);
int					ft_create_map(char *argv, t_env *fdf);
int					ft_draw_map(t_env *fdf);

int					key_hook(int keycode, t_env *fdf);
void				ft_mlx_key_hook_color(int keycode, t_env *fdf);


int					mouse_hook(int button, int x, int y, t_env *fdf);
int					expose_hook(t_env *fdf);

int					ft_draw_paral_lines(t_env *fdf);
int					ft_draw_iso_lines(t_env *fdf);
void				ft_bresenham_line(t_env*fdf);
int					ft_draw_paral_collumns(t_env *fdf);
int					ft_draw_iso_collumns(t_env *fdf);
void				ft_bresenham_col(t_env*fdf);

#endif
