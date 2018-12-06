/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tets_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:14:58 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/06 19:58:46 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		say_hello(t_win *win)
{
	void	*w;
	void	*mlx;

	w = win->win_ptr;
	mlx = win->mlx_ptr;
	mlx_string_put(mlx, w, WIDTH / 2 - 50, HEIGHT / 2 - 100,
					0x00FFFF, "Hi, i am FDF :)");
	mlx_string_put(mlx, w, WIDTH / 2 - 72, HEIGHT / 2 - 50,
					0x00FFFF, "Press enter to start");
	mlx_string_put(mlx, w, WIDTH / 2 - 138, HEIGHT / 2,
					0x00FFFF, "Press F to print Usage to console");
}

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

int				exit_hook(void)
{
	exit(0);
}

int				main(int argc, char **argv)
{
	t_win *win1;

	win1 = (t_win *)malloc(sizeof(t_win));
	if (argc != 2)
	{
		ft_putendl(USAGE);
		free(win1);
		exit(0);
	}
	if ((win1->map = readmap(argv[1])) == NULL)
	{
		ft_putendl("Something went wrong...");
		free(win1->map);
		free(win1);
		exit(0);
	}
	init_win(&win1);
	say_hello(win1);
	mlx_hook(win1->win_ptr, 2, 0, deal_key, (void *)win1);
	mlx_hook(win1->win_ptr, 17, 0, exit_hook, (void *)win1);
	mlx_mouse_hook(win1->win_ptr, mouse_pressed, (void *)win1);
	mlx_loop(win1->mlx_ptr);
	return (0);
}
