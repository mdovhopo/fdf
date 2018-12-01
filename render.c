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
	double	a;
	t_vec2	to_center;

	a = win->alpha * TO_RAD;
	to_center.x = win->map->sizex / 2;
	to_center.y = win->map->sizez / 2;
	z = -win->map->sizez / 2;
	while (z < win->map->sizez / 2 + if_odd(win->map->sizez))
	{
		x = -win->map->sizex / 2;
		while (x < win->map->sizex / 2 + if_odd(win->map->sizex))
		{
			y = -win->map->map[z + (int)to_center.y][x + (int)to_center.x];
			//vec = isoprojection(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a), (double)z, win); // by x
			//vec = isoprojection(x, y * cos(a) - z * sin(a), y * sin(a) + z * cos(a), win); // by z
			vec = isoprojection(x * cos(a) + z * sin(a), y, -x * sin(a) + z * cos(a), win); // by y
			//vec = isoprojection(x, y, z, win);
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
	grid(win, offsetx, offsety, res, repaint);
}
