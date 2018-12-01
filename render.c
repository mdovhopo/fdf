/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:45:48 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/27 15:45:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	show_rotation(t_win *win)
{
	t_vec3	vec_centr;
	t_vec3	vec_up;
	t_vec3	vec_left;
	t_vec3	vec_right;
	t_vec2	offset;

	offset.x = 50;
	offset.y = 110;
	vec_centr = isoprojection(0, 0, 0, win);
	vec_up = isoprojection(0, -50, 0, win);
	vec_left = isoprojection(0, 0, 50, win);
	vec_right = isoprojection(-50, 0, 0, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_up.x, offset.y + vec_up.y, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_left.x, offset.y + vec_left.y, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_right.x, offset.y + vec_right.y, win);
}

static void	static_elements(t_win *win)
{
	t_vec2 start;
	t_vec2 size;

	start.x = 0;
	start.y = 0;
	size.x = WIDTH;
	size.y = 60;
	//rect(start, size, win);
	//mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, 0xFFFFFF, "esc - close win;del - reset values; arrows - move image; scroll to zoom; R G B - swap color");
	show_rotation(win);
}

static int if_odd(int x)
{
	return (x % 2 == 0 ? 0 : 1);
}

static void	calculate_image(t_win *win)
{
	t_vec3	vec;
	int		x;
	int		z;
	int		y;
	t_vec2	to_center;

	to_center.x = win->map->sizex / 2;
	to_center.y = win->map->sizez / 2;
	z = -win->map->sizez / 2;
	while (z < win->map->sizez / 2 + if_odd(win->map->sizez))
	{
		x = -win->map->sizex / 2;
		while (x < win->map->sizex / 2 + if_odd(win->map->sizex))
		{
			y = -win->map->map[z + (int)to_center.y][x + (int)to_center.x];
			vec = isoprojection(x, y, z, win);
			win->bufferx[z + (int)to_center.y][x + (int)to_center.x] = vec.x;
			win->buffery[z + (int)to_center.y][x + (int)to_center.x] = vec.y;
			x++;
		}
		z++;
	}
}

void		render(t_win *win, short int repaint)
{
	int		res;
	int		offsetx;
	int		offsety;
	int		scale_res;

	res = (WIDTH / win->map->sizex) / 2;
	win->scale += (res + win->scale < MIN_RES ? 3 : 0);
	win->scale -= (res + win->scale > MAX_RES ? 3 : 0);
	res += win->scale;
	res = (res < MIN_RES ? MIN_RES : res);
	res = (res > MAX_RES ? MAX_RES : res);
	offsetx = WIDTH / 2;
	offsety = HEIGHT / 2;
	if (repaint == 1)
		calculate_image(win);
	printf("sizex: %i sizez %i\n", win->map->sizex, win->map->sizez);
	grid(win, offsetx, offsety, res, repaint);
	static_elements(win);
}
