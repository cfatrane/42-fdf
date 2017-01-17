/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 17:30:33 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

# define ESC 53

# define A 0
# define B 11
# define C 8
# define D 2
# define E 4
# define F 3
# define G 9
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6

# define ONE_NUM_PAD 83
# define TWO_NUM_PAD 84
# define THREE_NUM_PAD 85
# define FOUR_NUM_PAD 86
# define FIVE_NUM_PAD 87
# define SIX_NUM_PAD 88
# define SEVEN_NUM_PAD 89
# define EIGHT_NUM_PAD 91
# define NINE_NUM_PAD 92

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

# define ARROW 123 || 124 || 125 || 126

# define DX (abs(fdf->point.x2 - fdf->point.x1))
# define SX (fdf->point.x1 < fdf->point.x2 ? 1 : -1)
# define DY (abs(fdf->point.y2 - fdf->point.y1))
# define SY (fdf->point.y1 < fdf->point.y2 ? 1 : -1)
# define ERR ((fdf->point.dx > fdf->point.dy ? fdf->point.dx : -fdf->point.dy) / 2)

# define X1PL (fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z1PL)))
# define Y1PL (fdf->point.y + ((fdf->point.cte / 2) * (fdf->map.pad * Z1PL)))
# define Z1PL (fdf->map.map[fdf->map.y][fdf->map.x])
# define X2PL (fdf->point.x + fdf->point.spc) + (fdf->point.cte * (fdf->map.pad * Z2PL))
# define Y2PL (fdf->point.y + ((fdf->point.cte / 2) * (fdf->map.pad * Z2PL)))
# define Z2PL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define X1PC (fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z1PC)))
# define Y1PC (fdf->point.y + ((fdf->point.cte / 2) * (fdf->map.pad * Z1PC)))
# define Z1PC (fdf->map.map[fdf->map.y][fdf->map.x])
# define X2PC (fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z2PC)))
# define Y2PC (fdf->point.y + fdf->point.spc) + ((fdf->point.cte / 2) * (fdf->map.pad * Z2PC))
# define Z2PC (fdf->map.map[fdf->map.y + 1][fdf->map.x])

# define X1IL (fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * fdf->point.y)
# define Y1IL ((fdf->point.pos * Z1IL) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y)
# define Z1IL (fdf->map.map[fdf->map.y][fdf->map.x])
# define X2IL (fdf->point.cte1 * (fdf->point.x + fdf->point.spc)- fdf->point.cte2 * fdf->point.y)
# define Y2IL ((fdf->point.pos * Z2IL) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * (fdf->point.y + fdf->point.spc))
# define Z2IL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define X1IC (fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * fdf->point.y)
# define Y1IC ((fdf->point.pos * Z1IC) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y)
# define Z1IC (fdf->map.map[fdf->map.y][fdf->map.x])
# define X2IC (fdf->point.cte1 * fdf->point.x - fdf->point.cte2 * (fdf->point.y + fdf->point.spc))
# define Y2IC (fdf->point.pos * Z2IC) + (fdf->point.cte1 / 2) * fdf->point.x + (fdf->point.cte2 / 2) * (fdf->point.y + fdf->point.spc)
# define Z2IC fdf->map.map[fdf->map.y + 1][fdf->map.x]

#endif
