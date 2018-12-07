/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:42:54 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/07 18:44:18 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_img(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
}
