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

static int		count_height(char *s)
{
	int		fd;
	char	*line;
	int		c_y;
	int		ret;

	c_y = 0;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		c_y++;
		free(line);
	}
	close(fd);
	return (c_y);
}

static int		fill_map(char *line, int *line_int)
{
	int	i;

	i = 0;
	while (*line)
	{
		while (*line == ' ')
		{
			line++;
			if (!*line)
				return (i);
		}
		line_int[i++] = ft_atoi((char *)line);
		while (*line != ' ')
		{
			if (!*line)
				return (i);
			line++;
		}
	}
	return (i);
}

static int		find_width(char *s, t_map *map, int *fd)
{
	char	*line;
	int		length;

	*fd = open(s, O_RDONLY);
	get_next_line(*fd, &line);
	map->sizex = ft_count_words((char *)line, ' ');
	if ((map->map[0] = (int *)malloc(sizeof(int *) * map->sizex)))
		fill_map(line, map->map[0]);
	else
		return (-42);
	return (1);
}

static void		free_map(t_map *map, int i)
{
	while (--i > -1)
		free(map->map[i]);
	free(map);
	write(1, WRONG_LINE_LENGTH, 18);
	exit(0);
}

t_map			*readmap(char *s)
{
	t_map	*map;
	int		i;
	char	*line;
	int		prev_line;
	int		fd;

	i = 1;
	map = (t_map *)malloc(sizeof(t_map *));
	if ((map->sizez = count_height(s)) < 0)
		return (NULL);
	map->map = (int **)malloc(sizeof(int *) * map->sizez);
	if ((find_width(s, map, &fd)) < 0)
		return (NULL);
	if (map->sizex < 0)
		return (NULL);
	prev_line = map->sizex;
	while (get_next_line(fd, &line) > 0)
	{
		map->map[i] = (int *)malloc(sizeof(int *) * map->sizex);
		if (prev_line != fill_map(line, map->map[i++]))
			free_map(map, i - 1);
		free(line);
	}
	close(fd);
	return (map);
}
