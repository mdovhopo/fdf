/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoprojection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:20:27 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/27 21:20:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	isoprojection(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = (1 / sqrt(6)) * (sqrt(3) * x + sqrt(3) * z);
	vec.y = (1 / sqrt(6)) * (-x + 2 * y + z);
	vec.z = (1 / sqrt(6)) * (sqrt(2) * x - sqrt(2) * y + sqrt(2) * z);
	return (vec);
}
