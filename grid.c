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

void	grid(t_win *win, int offsetx, int offsety, int res)
{
	int		tx;
	int		ty;
	int		x;
	int		z;

	tx = win->translate.x;
	ty = win->translate.y;
	z = -1;
	while (++z < win->map->sizez)
	{
		x = -1;
		while (++x < win->map->sizex)
		{
			if (x + 1 < win->map->sizex)
				line(ft_new_intvec2(offsetx + win->bufferx[z][x] * res + tx,
									offsety + win->buffery[z][x] * res + ty),
					ft_new_intvec2(offsetx + win->bufferx[z][x + 1] * res + tx,
							offsety + win->buffery[z][x + 1] * res + ty), win);
			if (z + 1 < win->map->sizez)
				line(ft_new_intvec2(offsetx + win->bufferx[z][x] * res + tx,
									offsety + win->buffery[z][x] * res + ty),
					ft_new_intvec2(offsetx + win->bufferx[z + 1][x] * res + tx,
							offsety + win->buffery[z + 1][x] * res + ty), win);
		}
	}
}
