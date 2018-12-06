/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:28:08 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/06 17:28:09 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	interface(t_win *win)
{
	void	*mlx;
	void	*w;

	w = win->win_ptr;
	mlx = win->mlx_ptr;
	mlx_string_put(mlx, w, 0, 0, 0xffffff, "alpha:");
	mlx_string_put(mlx, w, 0, 20, 0xffffff, "beta:");
	mlx_string_put(mlx, w, 0, 40, 0xffffff, "gamma:");
	mlx_string_put(mlx, w, 100, 0, 0xffffff, ft_itoa(win->alpha));
	mlx_string_put(mlx, w, 100, 20, 0xffffff, ft_itoa(win->beta));
	mlx_string_put(mlx, w, 100, 40, 0xffffff, ft_itoa(win->gamma));
	mlx_string_put(mlx, w, 140, 0, 0xffffff, "d_x:");
	mlx_string_put(mlx, w, 140, 20, 0xffffff, "d_y:");
	mlx_string_put(mlx, w, 140, 40, 0xffffff, "scale:");
	mlx_string_put(mlx, w, 200, 0, 0xffffff, ft_itoa((int)win->translate.x));
	mlx_string_put(mlx, w, 200, 20, 0xffffff, ft_itoa((int)win->translate.y));
	mlx_string_put(mlx, w, 200, 40, 0xffffff, ft_itoa((int)win->scale));
}
