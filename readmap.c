/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:10:50 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/28 16:10:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_gound(t_map *map)
{
	int		x;
	int		z;
	int 	min;

	z = 0;
	min = map->map[0][0];
	while (z < map->sizez)
	{
		x = 0;
		while (x < map->sizex)
		{
			if (map->map[z][x] < min)
				min = map->map[z][x];
			x++;
		}
		z++;
	}
	printf("min: %i\n", min);
	return (min);
}

static int	find_endl(char *s)
{
	int		x;

	x = 0;
	while (*s++)
		x += (*s == '\n' ? 1 : 0);
	return (x);
}

static int	count_height(char *s)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		c_y;

	c_y = 0;
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		c_y += find_endl(buff);
	}
	close(fd);
	return (c_y);
}

static void	fill_map(char *line, int *int_line)
{
	int 	i;

	i = 0;
	while (*line)
	{
		while (*line == ' ')
			line++;
		int_line[i] = ft_atoi((char *)line);
		while (*line != ' ' && *line)
			line++;
		i++;
	}
}

t_map		*readmap(char *s)
{
	int		fd;
	t_map	*map;
	int		i;
	char	*line;
	int 	status;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map *));
	if ((fd = open(s, O_RDONLY)) < 0)
		return (NULL);
	status = get_next_line(fd, &line);
	free(line);
	map->sizex = ft_count_words((char *)line, ' ');
	map->sizez = count_height(s);
	fd = open(s, O_RDONLY);
	map->map = (int **)malloc(sizeof(int *) * map->sizez);
	while ((get_next_line(fd, &line) > 0))
	{
		map->map[i] = (int *)malloc(sizeof(int *) * map->sizex);
		fill_map(line, map->map[i]);
		free(line);
		i++;
	}
	close(fd);
	return (map);
}