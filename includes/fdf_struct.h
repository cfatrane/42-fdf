/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 22:01:07 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 17:10:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				color;
	int				nblin;
	int				nbcol;
	int				max;
	int				pad;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	double			cte;
	double			cte1;
	double			cte2;
	int				pos;
	int				spc;
}					t_point;

typedef struct		s_mov
{
	int				l_r;
	int				d_u;
}					t_mov;

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
	int				keycode;
	struct s_color	color;
	struct s_map	map;
	struct s_point	point;
	struct s_mov	mov;
}					t_env;

#endif
