/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tets_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:14:58 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/23 13:19:01 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_win(t_win **window)
{
	t_win	*win;
	int		z;

	win = *window;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "MY LITTLE FDF");
	win->color = 0x00FFFF;
	win->scale = 0;
	win->translate.x = 0;
	win->translate.y = 0;
	win->alpha = 0;
	win->beta = 0;
	win->gamma = 0;
	win->bufferx = (double **)malloc(sizeof(double *) * win->map->sizez);
	win->buffery = (double **)malloc(sizeof(double *) * win->map->sizez);
	z = 0;
	while (z < win->map->sizez)
	{
		win->bufferx[z] = (double *)malloc(sizeof(double *) * win->map->sizex);
		win->buffery[z] = (double *)malloc(sizeof(double *) * win->map->sizex);
		z++;
	}
}

// TODO norme the libft and gnl and remove test

int				main(int argc, char **argv)
{
	t_win *win1;

	win1 = (t_win *)malloc(sizeof(t_win));
	if (argc != 2)
	{
		write(1, USAGE, 24);
		free(win1);
		exit(0);
	}
	if ((win1->map = readmap(argv[1])) == NULL)
	{
		write(1, NO_FILE, 30);
		free(win1->map);
		free(win1);
		exit(0);
	}
	init_win(&win1);
	render(win1, 1);
	mlx_key_hook(win1->win_ptr, deal_key, (void *)win1);
	mlx_mouse_hook(win1->win_ptr, mouse_pressed, (void *)win1);
	mlx_loop(win1->mlx_ptr);
	return (0);
}
