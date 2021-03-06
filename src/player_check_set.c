/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:04:47 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 14:30:10 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_is_win(t_fdf *env)
{
	if (env->player_c.y + 1 >= (env->width->y - 1))
		return (1);
	return (0);
}

int			ft_check_around(t_fdf *env)
{
	if (env->player_c.y >= 0 && env->player_c.y + 1 < env->width->y
			&& env->player_c.x - 1 >= 0 &&
			env->player_c.x < env->width->x &&
			env->tab[env->player_c.y][env->player_c.x].z == 0 &&
			env->tab[env->player_c.y][env->player_c.x - 1].z == 0 &&
			env->tab[env->player_c.y + 1][env->player_c.x].z == 0 &&
			env->tab[env->player_c.y + 1][env->player_c.x - 1].z == 0)
		return (1);
	else
		return (0);
}

void		ft_del_around(t_fdf *env)
{
	env->tab[env->player_c.y][env->player_c.x].z = 0;
	env->tab[env->player_c.y][env->player_c.x - 1].z = 0;
	env->tab[env->player_c.y + 1][env->player_c.x].z = 0;
	env->tab[env->player_c.y + 1][env->player_c.x - 1].z = 0;
}

void		ft_put_around(t_fdf *env)
{
	env->tab[env->player_c.y][env->player_c.x].z = env->val->player_size;
	env->tab[env->player_c.y][env->player_c.x - 1].z = env->val->player_size;
	env->tab[env->player_c.y + 1][env->player_c.x].z = env->val->player_size;
	env->tab[env->player_c.y + 1][env->player_c.x - 1].z =
		env->val->player_size;
}
