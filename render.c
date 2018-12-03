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

/*
** recalculate shows by what angle fdf must turn element
** 2 - by y
** 3 - by z
** 4 - by x
*/

static void		static_elements(t_win *win)
{
	void	*mlx;
	void	*w;

	w = win->win_ptr;
	mlx = win->mlx_ptr;
	rect(ft_new_vec2(0, 0), ft_new_vec2(WIDTH, 60), win);
	mlx_string_put(mlx, w, 0, 0, 0x000000, "esc - close win");
	mlx_string_put(mlx, w, 0, 20, 0x000000, "del - reset values");
	mlx_string_put(mlx, w, 0, 40, 0x000000, "arrows - move image");
	mlx_string_put(mlx, w, 200, 0, 0x000000, "scroll to zoom");
	mlx_string_put(mlx, w, 200, 20, 0x000000, "R G B - swap color");
	mlx_string_put(mlx, w, 400, 0, 0x000000, "4, 6 rotate by y");
	mlx_string_put(mlx, w, 400, 20, 0x000000, "8, 2 - rotate by z");
	mlx_string_put(mlx, w, 400, 40, 0x000000, "+, - rotate by x");
}

static t_vec3	rotation(t_vec3 location, t_win *win,
	unsigned short int recalculate)
{
	double	a;
	double	b;
	double	g;
	t_vec3	vec;

	a = win->alpha * TO_RAD;
	b = win->beta * TO_RAD;
	g = win->gamma * TO_RAD;
	if (recalculate == 1)
		vec = isoprojection(location.x, location.y, location.z);
	else if (recalculate == 2)
		vec = isoprojection(location.x * cos(a) + location.z * sin(a),
			location.y, -location.x * sin(a) + location.z * cos(a));
	else if (recalculate == 3)
		vec = isoprojection(location.x,
			location.y * cos(b) - location.z * sin(b),
			location.y * sin(b) + location.z * cos(b));
	else if (recalculate == 4)
		vec = isoprojection(location.x * cos(g) - location.y * sin(g),
			location.x * sin(g) + location.y * cos(g), location.z);
	return (vec);
}

static void		calculate_image(t_win *win, unsigned short int recalculate)
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
			vec = rotation(ft_new_vec3(x, y, z), win, recalculate);
			win->bufferx[z + (int)to_center.y][x + (int)to_center.x] = vec.x;
			win->buffery[z + (int)to_center.y][x + (int)to_center.x] = vec.y;
			x++;
		}
		z++;
	}
}

void			render(t_win *win, unsigned short int recalculate)
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
	if (recalculate > 0)
		calculate_image(win, recalculate);
	grid(win, offsetx, offsety, res);
	static_elements(win);
}
