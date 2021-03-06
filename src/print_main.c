/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:40:51 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/21 23:02:02 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putwin(t_fdf *env)
{
	mlx_string_put(env->ptr.mlx, env->ptr.win,
		LARGEUR / 2 - 120, HAUTEUR / 2 + 75, WHITE, "GG ! Press R to restart");
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
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 47, WHITE,
	"|     Altitude : + and -     |      Press U to unlock ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1090, 47, WHITE,
	env->val->p_mod == CONIQUE ? "Isometric" : "Parralelle");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 47, WHITE,
	"      |   Reset : R  |   Exit : ESC  |  Current mod :                |");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 65, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 65, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
}

void	ft_game_menu(t_fdf *env)
{
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 01, WHITE,
	(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -"));
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 01, WHITE,
	"  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 17, WHITE,
	"| Game mode activated, press R to leave it or to reset");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 535, 17, WHITE,
	"  the game |  Move Player : W / A / S / D  |  Projection mod : TAB  |");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 1, 32, WHITE,
	"  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - ");
	mlx_string_put(env->ptr.mlx, env->ptr.win, 530, 32, WHITE,
	" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
}

void	ft_outside_alert(t_fdf *env)
{
	mlx_string_put(env->ptr.mlx, env->ptr.win,
		LARGEUR / 2 - 180, HAUTEUR / 2 - 75, WHITE,
		"The map must fit in the window to use L");
}
