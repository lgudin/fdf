/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_setb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:12:21 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/21 17:31:54 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_pers(int keycode, t_fdf *env)
{
	if (env->width->x > 3 && env->width->y > 3)
	{
		ft_player_anim(env);
		env->val->color_mode = LABY;
		if (env->val->game != WIN)
		{
			if (keycode == W)
				ft_move_up(env);
			else if (keycode == A)
				ft_move_left(env);
			else if (keycode == S)
				ft_move_down(env);
			else if (keycode == D)
				ft_move_right(env);
			if (ft_is_win(env) == 1)
			{
				ft_del_around(env);
				env->val->game = WIN;
			}
		}
	}
}

void	ft_key_hook_reset(t_fdf *env)
{
	val_init(env->val);
	ft_del_around(env);
	ft_init_game(env);
}

void	ft_key_hook_set_regu_back(t_fdf *env)
{
	env->val->color_mode = REGULAR;
	env->val->y += env->layout.y;
	env->val->x += env->layout.x;
	env->stat_mode = REG_S;
}

void	ft_key_hook_set_lock(t_fdf *env)
{
	if ((env->val->inside = ft_is_inside(env)) == 1)
	{
		if (env->stat_mode == REG_S)
		{
			env->layout.y = 0;
			env->layout.x = 0;
			env->val->color_mode = DVD;
			dvd_color_set(env);
			ft_get_borne(env);
		}
		env->stat_mode = LOCK_S;
		ft_ca_bouge(env);
		if (ft_boing(env))
			dvd_color_set(env);
	}
}
