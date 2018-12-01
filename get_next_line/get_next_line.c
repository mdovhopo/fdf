/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:19:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/12 20:04:09 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		set_line(t_gnl **tmp, char *data, char **line)
{
	t_gnl	*lst;

	lst = *tmp;
	if (!data || data[0] == '\0')
		return (0);
	if (!(ft_strchr(data, '\n')))
	{
		*line = ft_strdup(data);
		lst->data = NULL;
		return (1);
	}
	*line = ft_strsub(data, 0, (size_t)(ft_strchr(data, '\n') - data));
	lst->data = ft_strdup(ft_strchr(data, '\n') + 1);
	ft_strdel(&data);
	return (1);
}

static t_gnl	*lst_new(int fd)
{
	t_gnl	*new_lst;

	new_lst = (t_gnl *)malloc(sizeof(t_list));
	if (new_lst)
	{
		new_lst->data = NULL;
		new_lst->fd = fd;
		new_lst->next = NULL;
	}
	return (new_lst);
}

static t_gnl	*find_elem(int fd, t_gnl **lst)
{
	t_gnl	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = lst_new(fd);
	tmp->next = *lst;
	*lst = tmp;
	tmp = *lst;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	char			buffer[BUFF_SIZE + 1];
	t_gnl			*curr_fd;
	char			*tmp;
	int				read_bytes;

	if (CHECK_ERRORS(fd, line, buffer))
		return (ERROR);
	curr_fd = find_elem(fd, &lst);
	*line = NULL;
	if (!curr_fd->data)
		curr_fd->data = ft_strnew(0);
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(curr_fd->data, buffer);
		free(curr_fd->data);
		curr_fd->data = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (!read_bytes)
		if (curr_fd->data)
			return (set_line(&curr_fd, curr_fd->data, line));
	return (set_line(&curr_fd, curr_fd->data, line));
}
