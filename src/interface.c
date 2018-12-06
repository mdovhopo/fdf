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

static void bolshit(char **s, void *mlx, void *w)
{
	mlx_string_put(mlx, w, 0, 0, 0xffffff, "alpha:");
	mlx_string_put(mlx, w, 0, 20, 0xffffff, "beta:");
	mlx_string_put(mlx, w, 0, 40, 0xffffff, "gamma:");
	mlx_string_put(mlx, w, 100, 0, 0xffffff, s[0]);
	mlx_string_put(mlx, w, 100, 20, 0xffffff, s[1]);
	mlx_string_put(mlx, w, 100, 40, 0xffffff, s[2]);
	mlx_string_put(mlx, w, 140, 0, 0xffffff, "d_x:");
	mlx_string_put(mlx, w, 140, 20, 0xffffff, "d_y:");
	mlx_string_put(mlx, w, 140, 40, 0xffffff, "scale:");
	mlx_string_put(mlx, w, 200, 0, 0xffffff, s[3]);
	mlx_string_put(mlx, w, 200, 20, 0xffffff, s[4]);
	mlx_string_put(mlx, w, 200, 40, 0xffffff, s[5]);
}

void		interface(t_win *win)
{
	void	*mlx;
	void	*w;
	char	**s;
	int		i;

	i = 6;
	s = (char **)malloc(sizeof(char *) * 6);
	s[0] = ft_itoa(win->alpha);
	s[1] = ft_itoa(win->beta);
	s[2] = ft_itoa(win->gamma);
	s[3] = ft_itoa((int)win->translate.x);
	s[4] = ft_itoa((int)win->translate.y);
	s[5] = ft_itoa((int)win->scale);
	w = win->win_ptr;
	mlx = win->mlx_ptr;
	bolshit(s, mlx, w);
	while (--i > -1)
		free(s[i]);
	free(s);
}
