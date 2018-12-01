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

t_vec3 	isoprojection(int x, int y, int z, t_win *win)
{
	t_vec3	vec;
	double	a;
	double	b;
/*
	//a = 35.264 * TO_RAD;
	//b = 45 * TO_RAD;
	a = *win->alpha * TO_RAD;
	b = *win->beta * TO_RAD;
	vec.x = x * cos(b) - z * sin(a);
	vec.y = x * sin(a) * sin(b) + y * cos(a) + z * sin(a) * cos(b);
	vec.z = x * sin(b) * cos(a) - y * sin(a) + z * cos(a) * cos(b);


	vec.x = (1 / sqrt(6)) * (sqrt(3) * x - sqrt(3) * z);
	vec.y = (1 / sqrt(6)) * (x + 2 * y + z);
	vec.z = (1 / sqrt(6)) * (sqrt(2) * x - sqrt(2) * y + sqrt(2) * z);
*/
	vec.x = (1 / sqrt(6)) * (sqrt(3) * x + sqrt(3) * z);
	vec.y = (1 / sqrt(6)) * (-x + 2 * y + z);
	vec.z = (1 / sqrt(6)) * (sqrt(2) * x - sqrt(2) * y + sqrt(2) * z);
	return (vec);
}
