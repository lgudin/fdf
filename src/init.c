/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:10:55 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 14:29:17 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ptr_init(t_ptr *ptr)
{
	ptr->endian = 0;
	ptr->bpp = 32;
	ptr->size_line = LARGEUR * 4;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, LARGEUR, HAUTEUR, "FDF");
}

void	val_init(t_event *val)
{
	val->angle = 0.5;
	val->x = 0;
	val->y = 0;
	val->alti = INIT_ALTI;
	val->color_mode = REGULAR;
	val->p_mod = PARA;
	val->p_mod = PARA;
	val->game = LOOSE;
}

void	ft_init(t_fdf *env)
{
	val_init(env->val);
	ptr_init(&env->ptr);
	ft_init_game(env);
	env->stat_mode = REG_S;
	env->width->y = 0;
	env->width->x = 0;
}

void	ft_init_game(t_fdf *env)
{
	env->val->game = LOOSE;
	env->player_c.y = 0;
	env->player_c.x = 0;
	while (!(ft_check_around(env) == 1) && env->player_c.x < env->width->x)
		env->player_c.x++;
}
