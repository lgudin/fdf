/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besenham_tarace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:41:57 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/14 22:49:09 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	function(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	int			decision;
	int			yi;
	t_cursor	d;
	t_cursor	c;

	d.y = point_one.y - point_zero.y;
	d.x = point_one.x - point_zero.x;
	yi = 1;
	if (d.y < 0)
		yi *= -1;
	decision = 2 * yi * d.y - d.x;
	c.y = point_zero.y;
	c.x = point_zero.x;
	while (c.x <= point_one.x)
	{
		ft_put_pixel(env, c.x, c.y, point_zero.color);
		if (decision > 0)
		{
			c.y += yi;
			decision -= 2 * d.x;
		}
		decision += 2 * d.y * yi;
		c.x++;
	}
	return (0);
}

int	another_function(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	int			decision;
	int			xi;
	t_cursor	d;
	t_cursor	c;

	d.y = point_one.y - point_zero.y;
	d.x = point_one.x - point_zero.x;
	xi = 1;
	if (d.x < 0)
		xi *= -1;
	decision = 2 * d.x * xi - d.y;
	c.x = point_zero.x;
	c.y = point_zero.y;
	while (c.y <= point_one.y)
	{
		ft_put_pixel(env, c.x, c.y, point_zero.color);
		if (decision > 0)
		{
			c.x += xi;
			decision -= 2 * d.y;
		}
		decision += 2 * d.x * xi;
		c.y++;
	}
	return (0);
}

int	draw_line(t_fdf *env, t_proj point_zero, t_proj point_one)
{
	if (labs(point_one.y - point_zero.y) < labs(point_one.x - point_zero.x))
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
