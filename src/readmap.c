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

	c_y = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
	{
		ft_putendl(NO_FILE);
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		c_y++;
		free(line);
	}
	close(fd);
	if (c_y < 2)
	{
		ft_putendl("map height can't be less than 2");
		exit(0);
	}
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

static void		find_width(char *s, t_map *map, int *fd)
{
	char	*line;

	*fd = open(s, O_RDONLY);
	get_next_line(*fd, &line);
	map->sizex = ft_count_words((char *)line, ' ');
	map->map[0] = (int *)malloc(sizeof(int *) * map->sizex);
	fill_map(line, map->map[0]);
	free(line);
	if (map->sizex < 2)
	{
		ft_putendl("map width can't be less than 2");
		exit(0);
	}
}

static void		free_map(t_map *map, int i)
{
	while (--i > -1)
		free(map->map[i]);
	free(map);
	ft_putendl(WRONG_LINE_LENGTH);
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
	map->sizez = count_height(s);
	map->map = (int **)malloc(sizeof(int *) * map->sizez);
	find_width(s, map, &fd);
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
