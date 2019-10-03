/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besenham_tarace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:41:57 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/03 21:53:56 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	function(t_pt point_zero, t_pt point_one, t_ptr ptr)
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
		/*if (x >= 0 && y >= 0 && x < width.x && y < width.y)
			(*fdf)->image_grid[y][x] = MID_COLOR(point_one.color, point_zero.color);
		*/
    mlx_pixel_put(ptr.mlx, ptr.win, x, y, point_zero.color);
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

int	another_function(t_pt point_zero, t_pt point_one, t_ptr ptr)
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
		/*
    if (x >= 0 && y >= 0 && x < IMAGE_X && y < IMAGE_Y)
			(*fdf)->image_grid[y][x] = MID_COLOR(point_one.color, point_zero.color);
    */
    mlx_pixel_put(ptr.mlx, ptr.win, x, y, point_zero.color);
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

int	draw_line(t_pt point_zero, t_pt point_one, t_ptr ptr)
{
	if (fabsf(point_one.y - point_zero.y) < fabsf(point_one.x - point_zero.x))
	{
		if (point_zero.x > point_one.x)
			function(point_one, point_zero, ptr);
		else
			function(point_zero, point_one, ptr);
	}
	else
	{
		if (point_zero.y > point_one.y)
			another_function(point_one, point_zero, ptr);
		else
			another_function(point_zero, point_one, ptr);
	}
	return (0);
}