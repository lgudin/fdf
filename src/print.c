/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/16 16:07:14 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y, t_rgb color)
{
	int calculation;

	if (env->stat_mode == LOCK_S)
	{
		x += env->layout.x;
		y += env->layout.y;
	}
	calculation = (x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line);
	if (x <= LARGEUR && x >= 0 && y <= HAUTEUR && y >= 0 && calculation
			+ 3 < HAUTEUR * LARGEUR * 4
			&& calculation < 2147483647 && calculation > -2147483648)
	{
		env->ptr.img_data[calculation] = color.color_r;
		env->ptr.img_data[calculation + 1] = color.color_g;
		env->ptr.img_data[calculation + 2] = color.color_b;
	}
}

void	fill_image(t_fdf *env)
{
	t_cursor c;

	c.y = -1;
	while (++c.y < env->width->y)
	{
		c.x = -1;
		while (++c.x < env->width->x)
		{
			if (c.x + 1 < env->width->x)
			{
				draw_line(env, env->proj[c.y][c.x], env->proj[c.y][c.x + 1]);
			}
			if (c.y + 1 < env->width->y)
			{
				draw_line(env, env->proj[c.y][c.x], env->proj[c.y + 1][c.x]);
			}
		}
	}
}

void	ft_print_menu(t_fdf *env)
{
	
	if (env->stat_mode == LOCK_S)
		ft_lock_menu(env);
	if (env->val->color_mode == LABY)
		ft_game_menu(env);
	if (env->stat_mode != LOCK_S && env->val->color_mode != LABY)
		ft_regular_menu(env);
	if (env->val->game == WIN && env->stat_mode != LOCK_S)
		ft_putwin(env);
}
