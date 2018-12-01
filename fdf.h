/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/27 15:16:10 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "get_next_line/libft/libft.h"

# define WIDTH 2000
# define HEIGHT 1200
# define TO_RAD M_PI / 180
# define TO_DEGREE 180 / M_PI
# define MIN_RES 4
# define MAX_RES 150

typedef struct 	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct 	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct s_map
{
	int			**map;
	int			sizex;
	int			sizez;
	int			min_atitude;
}				t_map;

typedef struct 	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			scale;
	int			color;
	double		*alpha;
	double		*beta;
	t_vec2		translate;
	t_map		*map;
	double		**bufferx;
	double		**buffery;
}				t_win;

t_map	*readmap(char *s);
void	render(t_win *win, short int repaint);
void	grid(t_win *win, int offsetx, int offsety, int res, short int repaint);
void	line(int x1, int y1, int x2, int y2, t_win *win);
t_vec3	vec3d(int x, int y, int z);
t_vec3 	isoprojection(int x, int y, int z, t_win *win);
void	inc_dec_z(t_map *map, int sign);
void	rect(t_vec2 start, t_vec2 size, t_win *win);
void	rotate(t_win *win);
void	del_win(t_win *win);

#endif