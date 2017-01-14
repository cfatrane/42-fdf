/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:29:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/14 22:01:38 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "fdf_define.h"
# include "fdf_struct.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIN_LENGHT 1000
# define WIN_WIDTH 1000

# define WHITE 0xFFFFFF

/*
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x008000
*/
int					ft_fdf(char *argv);

int					ft_create_map(char *argv, t_env *fdf);
int					ft_mlx(t_env *fdf);

int					ft_key_hook(int keycode, t_env *fdf);
void				ft_key_hook_color(int keycode, t_env *fdf);
void				ft_key_hook_move(int key_hook, t_env *fdf);

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
