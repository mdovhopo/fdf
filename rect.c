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
	while (start.y < size.y)
	{
		line(start.x, start.y, size.x, start.y, win);
		start.y++;
	}
}
