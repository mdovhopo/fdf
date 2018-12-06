/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:53:40 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/30 12:54:25 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rect(t_vec2 start, t_vec2 size, t_win *win)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	size_x = start.x + size.x;
	size_y = start.y + size.y;
	y = (int)start.y;
	while (y < size_y)
	{
		x = (int)start.x;
		while (x < size_x)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
			x++;
		}
		y++;
	}
}
