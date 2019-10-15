/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 15:58:30 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_hook(int keycode, t_fdf *env)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == U && env->stat_mode == LOCK_S)
		ft_key_hook_set_regu_back(env);
	else if (keycode == L || env->stat_mode == LOCK_S)
		ft_key_hook_set_lock(env);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
			|| keycode == DOWN_ARROW || keycode == UP_ARROW)
		ft_key_hook_move(keycode, env);
	else if (keycode == I || keycode == O)
		ft_key_hook_zoom(keycode, env->val);
	else if (keycode == R)
		ft_key_hook_reset(env);
	else if (keycode == MORE || keycode == LESS)
		ft_key_hook_alti(keycode, env->val);
	else if (keycode == C)
		ft_key_hook_color_mode(env->val);
	else if (keycode == TABULATION)
		ft_key_hook_proj_mode(env->val);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		ft_move_pers(keycode, env);
	ft_expose_hook(env);
	return (0);
}

int		ft_expose_hook(t_fdf *env)
{
	if (!(env->ptr.img = mlx_new_image(env->ptr.mlx, LARGEUR, HAUTEUR)))
		return ((int)ft_error("mlx_new_image passe pas"));
	env->ptr.img_data = mlx_get_data_addr(env->ptr.img,
			&env->ptr.bpp, &env->ptr.size_line, &env->ptr.endian);
	if (env->stat_mode == REG_S && env->val->p_mod == CONIQUE)
		projection_tintintin(env);
	else if (env->stat_mode == REG_S && env->val->p_mod == PARA)
		projection_para(env);
	else if (!(env->stat_mode == LOCK_S))
		return ((int)ft_error("Aucun mode de projection"));
	fill_image(env);
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
	mlx_destroy_image(env->ptr.mlx, env->ptr.img);
	ft_print_menu(env);
	return (0);
}
