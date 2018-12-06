/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:21:13 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/04 18:23:12 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_usage(void)
{
	ft_putendl("===================");
	ft_putendl("FDF Usage:");
	ft_putendl("esc - close win");
	ft_putendl("del - reset values");
	ft_putendl("arrows - move image");
	ft_putendl("scroll to zoom");
	ft_putendl("R G B - swap color");
	ft_putendl("4, 6 rotate by y");
	ft_putendl("8, 2 - rotate by z");
	ft_putendl("+, - rotate by x");
	ft_putendl("===================");
}
