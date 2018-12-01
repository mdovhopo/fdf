/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:20:29 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/27 16:20:30 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** win->buffer is 3d array, that contains 2 2d arrays:
** 1 - is for x values; 2 - is for y values;
*/

void	grid(t_win *win, int offsetx, int offsety, int res, short int repaint)
{
	int		tx = win->translate.x;
	int		ty = win->translate.y;

	for (int z = 0; z < win->map->sizez; z++)
	{
		for (int x = 0; x < win->map->sizex; x++)
		{

			if (x + 1 < win->map->sizex)
			{
				line(offsetx + win->bufferx[z][x] * res + tx, offsety + win->buffery[z][x] * res + ty,
					offsetx + win->bufferx[z][x + 1] * res + tx, offsety + win->buffery[z][x + 1] * res + ty, win); // x + 1
			}
			if (z + 1 < win->map->sizez)
			{
				line(offsetx + win->bufferx[z][x] * res + tx, offsety + win->buffery[z][x] * res + ty,
					offsetx + win->bufferx[z + 1][x] * res + tx, offsety + win->buffery[z + 1][x] * res + ty, win); // z + 1
			}
			//mlx_pixel_put(win->mlx_ptr, win->win_ptr, offsetx + win->buffer[0][z][x] * res + tx, offsety + win->buffer[1][z][x] * res + ty, 0xff0000);
		}
	}
}
