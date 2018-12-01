/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:59:38 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/30 18:59:39 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_win(t_win *win)
{
	int		z;

	z = 0;
	while (z < win->map->sizez) // 0 - x 1 - y
	{
		free(win->bufferx[z]);
		free(win->buffery[z]);
		z++;
	}
	free(win->bufferx);
	free(win->buffery);
	z = 0;
	while (z < win->map->sizez)
	{
		free(win->map->map[z]);
		z++;
	}
	free(win->map->map);
}
