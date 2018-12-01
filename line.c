/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:22:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/27 16:22:45 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(int x1, int y1, int x2, int y2, t_win *win)
{
	int deltaX = abs(x2 - x1);
	int deltaY = abs(y2 - y1);
	int signX = x1 < x2 ? 1 : -1;
	int signY = y1 < y2 ? 1 : -1;
	int deltaerr;
	int error = deltaX - deltaY;

	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x2, y2, win->color);
	while (x1 != x2 || y1 != y2) 
	{
		if (x1 > WIDTH || y1 > HEIGHT)
			;
		else if (x1 < 0 || y1 < 0)
			;
		else
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, win->color);
		deltaerr = error * 2;
		if (deltaerr > -deltaY) 
		{
			error -= deltaY;
			x1 += signX;
		}
		if (deltaerr < deltaX) 
		{
			error += deltaX;
			y1 += signY;
		}
	}
}
