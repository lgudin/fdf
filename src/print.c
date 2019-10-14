/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/14 17:59:09 by lgudin           ###   ########.fr       */
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

void	ft_puttxt(t_fdf *env)
{
	if (env->stat_mode == LOCK_S)
		ft_lock_menu(env);
	else
		ft_regular_menu(env);
}

void	ft_lock_menu(t_fdf *env)
{
	mlx_string_put(env->ptr.mlx, env->ptr.win,
		LARGEUR / 2 - 120, HAUTEUR / 2, WHITE, "PRESS U TO UNLOCK");
}

void	ft_regular_menu(t_fdf *env)
{
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 01, WHITE,
	(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -"));
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 01, WHITE,
	"  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 17, WHITE,
	"| Zoom   : I and O   |   Color mod : C  |  Lock screen");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 17, WHITE,
	" : L   |   Move : UP / LEFT / DOWN / RIGHT  |  Projection mod : TAB  |");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 32, WHITE,
	"|-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 32, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - |");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 380, 47,
	WHITE, ft_itoa(env->val->color_mode));
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 47, WHITE,
	"| Altitude : + and - |  Current mod:    |  Press U to ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1090, 47, WHITE,
	env->val->p_mod == CONIQUE ? "Conique" : "Parralelle");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 47, WHITE,
	" unlock |   Reset : R  |   Exit : ESC  |  Current mod :              |");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 65, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 65, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
}
