/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vector3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:07:11 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/08 14:08:15 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3d	ft_new_vect3d(int x, int y, int z)
{
	t_vector3d vect3d;

	vect3d.x = x;
	vect3d.y = y;
	vect3d.z = z;
	return (vect3d);
}
