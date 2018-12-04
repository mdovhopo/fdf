/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:39:08 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/04 18:39:11 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int			length(char *s)
{
	int len;

	len = 0;
	while (((s[len] > 47 && s[len] < 58)
		|| (s[len] > 64 && s[len] < 71)) && s[len])
		len++;
	return (len);
}

static int			is_white_space(char *s)
{
	if (*s == ' ' || *s == '\t' || *s == '\v' ||
			*s == '\n' || *s == '\r' || *s == '\f')
		return (1);
	else
		return (0);
}

int					ft_atoi16(const char *str)
{
	int				res;
	int				len;
	int				base;
	char			*s;
	int				tmp;

	res = 0;
	base = 1;
	s = (char *)str;
	s += 2;
	while ((is_white_space(s)) && *s != '\0')
		s++;
	len = length(s);
	while (len > 0 && ((s[len - 1] > 47 && s[len - 1] < 58)
		|| (s[len - 1] > 64 && s[len - 1] < 71)))
	{
		if (s[len - 1] > 64 && s[len - 1] < 71)
			tmp = s[len - 1] - 55;
		else
			tmp = s[len - 1] - '0';
		res += tmp * base;
		base *= 16;
		len--;
	}
	return (res);
}
