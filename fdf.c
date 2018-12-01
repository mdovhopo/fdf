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

static void	show_rotation(t_win *win)
{
	t_vec3	vec_centr;
	t_vec3	vec_up;
	t_vec3	vec_left;
	t_vec3	vec_right;
	t_vec2	offset;

	offset.x = 50;
	offset.y = 110;
	vec_centr = isoprojection(0, 0, 0, win);
	vec_up = isoprojection(0, -50, 0, win);
	vec_left = isoprojection(0, 0, 50, win);
	vec_right = isoprojection(-50, 0, 0, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_up.x, offset.y + vec_up.y, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_left.x, offset.y + vec_left.y, win);
	line(offset.x + vec_centr.x, offset.y + vec_centr.y, offset.x + vec_right.x, offset.y + vec_right.y, win);
}

static void	static_elements(t_win *win)
{
	t_vec2 start;
	t_vec2 size;

	start.x = 0;
	start.y = 0;
	size.x = WIDTH;
	size.y = 60;
	rect(start, size, win);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, 0xFFFFFF, "esc - close win;del - reset values; arrows - move image; scroll to zoom; R G B - swap color");
	show_rotation(win);
}

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
		win->alpha = 0;
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
	else if (key == 88 || key == 86)
	{
		win->alpha += key == 88 ? 1 : -1;
		if (win->alpha == 360)
			win->alpha = 0;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		render(win, 1);
	}
	printf("you just pressed key with keyCode: %i\n", key);
	return (0);
}

static void		init_win(t_win **window)
{
	t_win *win;
	int 	z;


	win = *window;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "MY LITTLE FDF");
	
	win->color = 0x00FFFF;
	win->scale = 0;
	win->translate.x = 0;
	win->translate.y = 0;
	win->alpha = 0;

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

// TODO paralel and conic projection

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

	init_win(&win1);
	render(win1, 1);
	static_elements(win1);
	mlx_key_hook(win1->win_ptr, deal_key, (void *)win1);
	mlx_mouse_hook(win1->win_ptr, mouse_pressed, (void *)win1);
	mlx_loop(win1->mlx_ptr);
	return (0);
}
