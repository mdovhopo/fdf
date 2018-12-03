/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:19:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/01 15:20:26 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
typedef struct 	win_s
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int 		*bits_per_pixel;
	int 		*size_line;
	int 		*endian;
	char		*image;
}				win_t;

int delay_key(int key_code, void *param)
{
	win_t *win;

	win = (win_t *)param;
	if (key_code == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}

	printf("key with code: %i\n", key_code);
	return (0);
}

int	main(void)
{
	win_t *win;
	unsigned int rgb;

	char arr[800][600];

	for (int i = 0; i < 800; i++)
		for (int j = 0; j < 600; j++)
			arr[i][j] = 0;

	win = (win_t *)malloc(sizeof(win_t));

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 600, 800, "TESTING IMAGE");
	win->img_ptr = mlx_new_image(win->mlx_ptr, 600, 800);

	win->bits_per_pixel = (int *)malloc(sizeof(int *));
	win->size_line = (int *)malloc(sizeof(int *));
	win->endian = (int *)malloc(sizeof(int *));

	*win->bits_per_pixel = 1;
	*win->size_line = 600;
	*win->endian = 0;

	win->image = mlx_get_data_addr(win->img_ptr, win->bits_per_pixel, win->size_line, win->endian);
	rgb = mlx_get_color_value(win->mlx_ptr, 0xFFBF00);
	printf("%u\n", rgb);
	ft_show_binary(rgb);

	for (int i = 0; i < 800; i++)
	{
		
		for (int j = 0; j < *win->size_line;j += 4)
		{
			unsigned int tmp_rgb = rgb;
			win->image[i * *win->size_line + j] = tmp_rgb % 256;
			tmp_rgb /= 256;
			win->image[i * *win->size_line + j + 1] = tmp_rgb % 256;
			tmp_rgb /= 256;
			win->image[i * *win->size_line + j + 2] = tmp_rgb % 256;
			tmp_rgb /= 256;
			win->image[i * *win->size_line + j + 3] = 0;
		}
	}

	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);

	for (int i = 0; i < 600 && 0; i++)
		for (int j = 0; j < 800; j++)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i, j, 0x820505);

	mlx_key_hook(win->win_ptr, delay_key, (void *)win);
	mlx_loop(win->mlx_ptr);

	return 0;
}
*/



void drawline(int x0, int y0, int x1, int y1, t_win *win)
{
    int dx, dy, p, x, y;
 
    dx=x1-x0;
    dy=y1-y0;
 
    x=x0;
    y=y0;
 
    p=2*dy-dx;
 
    while(x<x1)
    {
        if(p>=0)
        {
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
            p=p+2*dy;
        }
        x=x+1;
    }
}

int key_d(int key, t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "MY LITTLE FDF");
	drawline(10, 10, 100, 400, win);
	mlx_key_hook(win->win_ptr, key_d, (void *)win);
	mlx_loop(win->mlx_ptr);
	return 0;
}
