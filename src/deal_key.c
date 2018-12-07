/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:09:40 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/03 17:09:41 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** press arrows to move image
*/

static void	translate(int key, t_win *win)
{
	if (key == 123 || key == 124)
	{
		win->translate.x += key == 123 ? 10 : -10;
		del_img(win);
		render(win);
	}
	else if (key == 126 || key == 125)
	{
		win->translate.y += key == 126 ? 10 : -10;
		del_img(win);
		render(win);
	}
}

/*
** press esc to close window
** del - to reset values
*/

static void	destroy_or_reset_window(int key, t_win *win)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (key == 117)
	{
		win->scale = (WIDTH / win->map->sizex) / 2;
		win->alpha = 0;
		win->beta = 0;
		win->gamma = 0;
		win->translate.x = 0;
		win->translate.y = 0;
		win->color = 0x00FFFF;
		del_img(win);
		render(win);
	}
}

/*
** press R G B buttons to change color
*/

static void	change_color(int key, t_win *win)
{
	if (key == 15)
		win->color = 0xFF0000;
	else
		win->color = key == 5 ? 0x00FF00 : 0x0000FF;
	del_img(win);
	render(win);
}

/*
** press 4, 6 to rotate by  y axes
** 8, 2 - rotate by z
** +, - rotate by x
*/

static void	rotate(int key, t_win *win)
{
	if (key == 88 || key == 86)
	{
		win->alpha += key == 88 ? 1 : -1;
		del_img(win);
		render(win);
	}
	else if (key == 91 || key == 84)
	{
		win->beta += key == 91 ? 1 : -1;
		del_img(win);
		render(win);
	}
	else if (key == 69 || key == 78)
	{
		win->gamma += key == 69 ? 1 : -1;
		if (win->gamma >= 360)
			win->gamma = 0;
		del_img(win);
		render(win);
	}
}

int			deal_key(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == 53 || key == 117)
		destroy_or_reset_window(key, win);
	if (key == 123 || key == 124 || key == 126 || key == 125)
		translate(key, win);
	else if (key == 15 || key == 5 || key == 11)
		change_color(key, win);
	else if (key == 88 || key == 86 || key == 91
		|| key == 84 || key == 69 || key == 78)
		rotate(key, win);
	else if (key == 3)
		print_usage();
	else if (key == 36)
	{
		del_img(win);
		render(win);
	}
	return (0);
}
