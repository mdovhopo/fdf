/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:09:03 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/03 17:09:30 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_pressed(int key, int x, int y, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == 5)
	{
		if (win->scale + 3 < MAX_RES)
		{
			win->scale += 3;
			del_img(win);
			render(win);
		}
	}
	else if (key == 4)
	{
		if (win->scale - 3 > MIN_RES)
		{
			win->scale -= 3;
			del_img(win);
			render(win);
		}
	}
	x = y;
	y = x;
	return (0);
}
