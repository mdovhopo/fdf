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
	t_win *win;

	win = (t_win *)param;
	if (key == 5)
	{
		win->scale += 3;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	else if (key == 4)
	{
		win->scale -= 3;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	return (0);
}
