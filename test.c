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

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 600, 800, "TESTING IMAGE");
	win->img_ptr = mlx_new_image(win->mlx_ptr, 200, 100);
	*win->bits_per_pixel = 3;
	*win->size_line = 20;


	win->image = mlx_get_data_addr(win->img_ptr, win->bits_per_pixel, win->size_line, win->endian);

	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 20, 40);

	mlx_key_hook(win->win_ptr, delay_key, (void *)win);
	mlx_loop(win->mlx_ptr);
	return 0;
}
