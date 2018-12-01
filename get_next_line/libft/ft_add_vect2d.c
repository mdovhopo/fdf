/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vect2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:10:51 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/08 14:54:54 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_vector2d	ft_add_vect2d(t_vector2d v1, t_vector2d v2)
{
	t_vector2d res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}
