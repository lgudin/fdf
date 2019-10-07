/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besenham_tarace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:41:57 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/07 14:35:36 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	function(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	int					decision;
	int					y;
	int					x;
	int					yi;
  int         dy = point_one.y - point_zero.y;
  int         dx = point_one.x - point_zero.x;

	yi = 1;
	if (dy < 0)
		yi *= -1;
	decision = 2 * yi * dy - dx;
	y = point_zero.y;
	x = point_zero.x;
	while (x <= point_one.x)
	{
		ft_put_pixel(env, x, y, point_zero.color);
    	if (decision > 0)
		{
			y += yi;
			decision -= 2 * dx;
		}
		decision += 2 * dy * yi;
		x++;
	}
	return (0);
}

int	another_function(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	int		decision;
	int		y;
	int		x;
	int   xi;
  int   dy = point_one.y - point_zero.y;
  int   dx = point_one.x - point_zero.x;

	xi = 1;
	if (dx < 0)
		xi *= -1;
	decision = 2 * dx * xi - dy;
	x = point_zero.x;
	y = point_zero.y;
	while (y <= point_one.y)
	{
		ft_put_pixel(env, x, y, point_zero.color);
		if (decision > 0)
		{
			x += xi;
			decision -= 2 * dy;
		}
		decision += 2 * dx * xi;
		y++;
	}
	return (0);
}

int	draw_line(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	if (fabsf(point_one.y - point_zero.y) < fabsf(point_one.x - point_zero.x))
	{
		if (point_zero.x > point_one.x)
			function(env, point_one, point_zero);
		else
			function(env, point_zero, point_one);
	}
	else
	{
		if (point_zero.y > point_one.y)
			another_function(env, point_one, point_zero);
		else
			another_function(env, point_zero, point_one);
	}
	return (0);
}