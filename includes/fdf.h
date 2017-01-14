/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 20:49:32 by cfatrane         ###   ########.fr       */
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

# define WIN_LENGHT 1000
# define WIN_WIDTH 1000

# define ESC 53
# define A 0
# define B 11
# define C 8
# define D 2
# define E 4
# define G 9
# define O 31
# define P 35
# define R 15

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

// White RGB code = 255*65536+255*256+255 = #FFFFFF

# define WHITE 0xFFFFFF

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
	int				pos;
	int				mv_l_r;
	int				mv_d_u;
	int				mv_left;
	int				mv_right;
	int				mv_up;
	int				mv_down;
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
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_lengh;
	int				win_width;
	int				nblin;
	int				nbcol;
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

void				ft_bresenham(t_env*fdf);
void				ft_pixel_put(t_env *fdf, int x, int y);

void				ft_proj(t_env *fdf);

int					ft_draw_paral_lines(t_env *fdf);
int					ft_draw_iso_lines(t_env *fdf);
int					ft_draw_paral_collumns(t_env *fdf);
int					ft_draw_iso_collumns(t_env *fdf);

#endif
