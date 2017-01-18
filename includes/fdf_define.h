/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/18 15:31:42 by cfatrane         ###   ########.fr       */
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

# define Z1PL (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2PL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define Z1PC (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2PC (fdf->map.map[fdf->map.y + 1][fdf->map.x])

# define Z1IL (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2IL (fdf->map.map[fdf->map.y][fdf->map.x + 1])

# define Z1IC (fdf->map.map[fdf->map.y][fdf->map.x])
# define Z2IC (fdf->map.map[fdf->map.y + 1][fdf->map.x])

#endif
