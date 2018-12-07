/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:45:48 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/04 17:16:33 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** recalculate shows by what angle fdf must turn element
** 2 - by y
** 3 - by z
** 4 - by x
*/

static t_vec3	rotation(t_vec3 location, t_win *win)
{
	double	a;
	double	b;
	double	g;
	t_vec3	vec;

	a = win->alpha * TO_RAD;
	b = win->beta * TO_RAD;
	g = win->gamma * TO_RAD;
	vec.x = location.x * cos(a) + location.z * sin(a);
	vec.y = location.y;
	vec.z = -location.x * sin(a) + location.z * cos(a);
	location = vec;
	vec.y = location.y * cos(b) - location.z * sin(b);
	vec.x = location.x;
	vec.z = location.y * sin(b) + location.z * cos(b);
	location = vec;
	vec.x = location.x * cos(g) - location.y * sin(g);
	vec.y = location.x * sin(g) + location.y * cos(g);
	vec.z = location.z;
	vec = isoprojection(vec.x, vec.y, vec.z);
	return (vec);
}

static void		calculate_image(t_win *win)
{
	t_vec3	vec;
	int		x;
	int		z;
	int		y;
	t_vec2	to_center;

	to_center.x = win->map->sizex / 2;
	to_center.y = win->map->sizez / 2;
	z = -win->map->sizez / 2;
	while (z < win->map->sizez / 2 + IS_ODD(win->map->sizez))
	{
		x = -win->map->sizex / 2;
		while (x < win->map->sizex / 2 + IS_ODD(win->map->sizex))
		{
			y = -win->map->map[z + (int)to_center.y][x + (int)to_center.x];
			vec = rotation(ft_new_vec3(x, y, z), win);
			win->bufferx[z + (int)to_center.y][x + (int)to_center.x] = vec.x;
			win->buffery[z + (int)to_center.y][x + (int)to_center.x] = vec.y;
			x++;
		}
		z++;
	}
}

void			render(t_win *win)
{
	int		offsetx;
	int		offsety;

	offsetx = WIDTH / 2;
	offsety = HEIGHT / 2;
	calculate_image(win);
	grid(win, offsetx, offsety, win->scale);
	interface(win);
}
