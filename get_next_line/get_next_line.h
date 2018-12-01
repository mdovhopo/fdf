/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:01:31 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/19 17:20:23 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define END_IS_ENDL(x) (x == '\n' ? 1 : 0)
# define END_IS_NULL(x) (x == '\0' ? 1 : 0)
# define STOP_READING break ;
# define CHECK_ERRORS(fd ,line, buff) (fd < 0 || !line || read(fd, buff, 0) < 0)
# define CHECK_IF_EXIT(d, f_ch, r_b) ((d == NULL || f_ch == '\0') && r_b == 0)
# define ERROR -1
# define SUCCESS_END 0

typedef struct	s_gnl
{
	int				fd;
	char			*data;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
