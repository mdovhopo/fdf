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

static void		static_elements(t_win *win)
{
	void	*mlx;
	void	*w;

	w = win->win_ptr;
	mlx = win->mlx_ptr;
	mlx_string_put(mlx, w, 0, 0, 0xffffff, "alpha:");
	mlx_string_put(mlx, w, 0, 20, 0xffffff, "beta:");
	mlx_string_put(mlx, w, 0, 40, 0xffffff, "gamma:");
	mlx_string_put(mlx, w, 100, 0, 0xffffff, ft_itoa(win->alpha));
	mlx_string_put(mlx, w, 100, 20, 0xffffff, ft_itoa(win->beta));
	mlx_string_put(mlx, w, 100, 40, 0xffffff, ft_itoa(win->gamma));
	mlx_string_put(mlx, w, 140, 0, 0xffffff, "d_x:");
	mlx_string_put(mlx, w, 140, 20, 0xffffff, "d_y:");
	mlx_string_put(mlx, w, 140, 40, 0xffffff, "scale:");
	mlx_string_put(mlx, w, 200, 0, 0xffffff, ft_itoa((int)win->translate.x));
	mlx_string_put(mlx, w, 200, 20, 0xffffff, ft_itoa((int)win->translate.y));
	mlx_string_put(mlx, w, 200, 40, 0xffffff, ft_itoa((int)win->scale));
}

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
	int		res;
	int		offsetx;
	int		offsety;

	res = (WIDTH / win->map->sizex) / 2;
	win->scale += (res + win->scale < MIN_RES ? 3 : 0);
	win->scale -= (res + win->scale > MAX_RES ? 3 : 0);
	res += win->scale;
	res = (res < MIN_RES ? MIN_RES : res);
	res = (res > MAX_RES ? MAX_RES : res);
	offsetx = WIDTH / 2;
	offsety = HEIGHT / 2;
	calculate_image(win);
	grid(win, offsetx, offsety, res);
	static_elements(win);
}
