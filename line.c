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

/*
** error.x - delta error
** error.y - error
*/

void	line(t_intvec2 start, t_intvec2 end, t_win *win)
{
	t_intvec2	delta;
	t_intvec2	sign;
	t_intvec2	error;

	delta = ft_new_intvec2(abs(end.x - start.x), -abs(end.y - start.y));
	sign = ft_new_intvec2(start.x < end.x ? 1 : -1, start.y < end.y ? 1 : -1);
	error = ft_new_intvec2(delta.x + delta.y, 2 * (delta.x + delta.y));
	while (start.x != end.x && start.y != end.y)
	{
		if (start.x > 0 && start.x < WIDTH && start.y > 60 && start.y < HEIGHT)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr,
				start.x, start.y, win->color);
		error.y = error.x * 2;
		if (error.y >= delta.y)
		{
			error.x += delta.y;
			start.x += sign.x;
		}
		if (error.y <= delta.x)
		{
			error.x += delta.x;
			start.y += sign.y;
		}
	}
}
