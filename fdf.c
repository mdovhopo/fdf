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

// flags for compile clang <source> -L <path to mlx> -lmlx -framework OpenGL -framework Appkit

// first param in coordinates is x, second - y

int 	mouse_pressed(int key, int x, int y, void *param)
{
	t_win *win;

	win = (t_win *)param;
	if (key == 5)
	{
		win->scale += 3;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	else if (key == 4)
	{
		win->scale -= 3;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}

	printf("you just pressed mousekey with mouseKeyCode: %i\n", key);
	return (0);
}

int 	deal_key(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == 53) // esc - close window
	{
		del_win(win);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		//TODO implement freeing the members of win struct 
		exit(0);
	}
	else if (key == 117) // del - reset val
	{
		win->scale = 0;
		win->translate.x = 0;
		win->translate.y = 0;
		win->color = 0x00FFFF;
		mlx_clear_window (win->mlx_ptr, win->win_ptr);
		render(win, 1);
	}
	else if (key == 123 || key == 124) // arrows
	{
		win->translate.x += key == 123 ? 10 : -10;
		mlx_clear_window (win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	else if (key == 126 || key == 125) // arrows
	{
		win->translate.y += key == 126 ? 10 : -10;
		mlx_clear_window (win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	else if (key == 15 || key == 5 || key == 11) // R G B
	{
		if (key == 15)
			win->color = 0xFF0000;
		else
			win->color = key == 5 ? 0x00FF00 : 0x0000FF;  
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 0);
	}
	printf("you just pressed key with keyCode: %i\n", key);
	return (0);
}

static void		init_win(t_win **window)
{
	t_win *win;
	int 	z;

	win = *window;
	win->color = 0x00FFFF;
	win->scale = 0;
	win->translate.x = 0;
	win->translate.y = 0;

	// TODO try to check if it works with only 2d array of buffer...
	//win->buffer = (double ***)malloc(sizeof(double) * 2);
	win->bufferx = (double **)malloc(sizeof(double *) * win->map->sizez);
	win->buffery = (double **)malloc(sizeof(double *) * win->map->sizez);
	z = 0;
	while (z < win->map->sizez) // 0 - x 1 - y
	{
		win->bufferx[z] = (double *)malloc(sizeof(double *) * win->map->sizex);
		win->buffery[z] = (double *)malloc(sizeof(double *) * win->map->sizex);
		z++;
	}
}

int				main(int argc, char **argv)
{
	t_win *win1;

	win1 = (t_win *)malloc(sizeof(t_win));
	if (argc != 2)
	{
		printf("amount of files must be 1\n");
		exit(0);

	}
	if ((win1->map = readmap(argv[1])) == NULL)
	{
		printf("no such file\n");
		exit(0);
	}
	if ((win1->mlx_ptr = mlx_init()) == NULL)
	{
		printf("mlxerr\n");
		free(win1);
		return (0);
	}
	if ((win1->win_ptr = mlx_new_window(win1->mlx_ptr, WIDTH, HEIGHT, "MY LITTLE FDF")) == NULL)
	{
		printf("winerr\n");
		free(win1);
		return (0);
	}
	init_win(&win1);
	render(win1, 1);
	mlx_key_hook(win1->win_ptr, deal_key, (void *)win1);
	mlx_mouse_hook(win1->win_ptr, mouse_pressed, (void *)win1);
	mlx_loop(win1->mlx_ptr);
	return (0);
}
