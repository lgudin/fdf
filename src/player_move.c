/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:06:39 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 15:02:32 by lgudin           ###   ########.fr       */
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
