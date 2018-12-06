/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/04 15:05:50 by mdovhopo         ###   ########.fr       */
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
# include "get_next_line.h"
# include "libft.h"

# define WIDTH 2000
# define HEIGHT 1200
# define IS_ODD(x) (x % 2 == 0 ? 0 : 1)
# define TO_RAD M_PI / 180
# define TO_DEGREE 180 / M_PI
# define MIN_RES 4
# define MAX_RES 150
# define USAGE "Usage: ./fdf <filename>\n"
# define WRONG_LINE_LENGTH "wrong line length\n"
# define NO_FILE "no such file or file is empty\n"

typedef struct	s_map
{
	int			**map;
	int			sizex;
	int			sizez;
	int			min_atitude;
}				t_map;

/*
** struct for window, created via mlx
** scale - for zoom, color - default color of image
** alpha, beta, gamma - angles rotation by y, z, x
** translate - for moving image
** map - pointer to map struct with parametrs for map
** bufferx, y arrays, forreal coordinates of drawing points on screen
*/

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			scale;
	int			color;
	int			alpha;
	int			beta;
	int			gamma;
	t_vec2		translate;
	t_map		*map;
	double		**bufferx;
	double		**buffery;
}				t_win;

t_map			*readmap(char *s);
void			render(t_win *win);
void			grid(t_win *win, int offsetx, int offsety, int res);
void			line(t_intvec2 start, t_intvec2 end, t_win *win);
t_vec3			isoprojection(double x, double y, double z);
void			inc_dec_z(t_map *map, int sign);
void			rect(t_vec2 start, t_vec2 size, t_win *win);
void			del_win(t_win *win);
int				mouse_pressed(int key, int x, int y, void *param);
int				deal_key(int key, void *param);
void			print_usage(void);
void			interface(t_win *win);

#endif
