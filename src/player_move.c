/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:06:39 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 14:31:35 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_down(t_fdf *env)
{
	ft_del_around(env);
	env->player_c.y++;
	if (ft_check_around(env))
	{
		env->player_c.y--;
		ft_del_around(env);
		env->player_c.y++;
		ft_put_around(env);
	}
	else
	{
		env->player_c.y--;
		ft_put_around(env);
	}
}

void	ft_move_up(t_fdf *env)
{
	ft_del_around(env);
	env->player_c.y--;
	if (ft_check_around(env))
	{
		env->player_c.y++;
		ft_del_around(env);
		env->player_c.y--;
		ft_put_around(env);
	}
	else
	{
		env->player_c.y++;
		ft_put_around(env);
	}
}

void	ft_move_left(t_fdf *env)
{
	ft_del_around(env);
	env->player_c.x--;
	if (ft_check_around(env))
	{
		env->player_c.x++;
		ft_del_around(env);
		env->player_c.x--;
		ft_put_around(env);
	}
	else
	{
		env->player_c.x++;
		ft_put_around(env);
	}
}

void	ft_move_right(t_fdf *env)
{
	ft_del_around(env);
	env->player_c.x++;
	if (ft_check_around(env))
	{
		env->player_c.x--;
		ft_del_around(env);
		env->player_c.x++;
		ft_put_around(env);
	}
	else
	{
		env->player_c.x--;
		ft_put_around(env);
	}
}

void	ft_player_anim(t_fdf *env)
{
	static short store = -1;

	if (store == -1)
		env->val->player_size = 2;
	if (env->val->player_size >= 3)
		store = 1;
	if (env->val->player_size < 3 && store == 0)
		env->val->player_size += 0.3;
	else
		env->val->player_size -= 0.3;
	if (env->val->player_size < 2)
		store = 0;
}
