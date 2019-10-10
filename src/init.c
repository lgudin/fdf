/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:10:55 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/10 15:10:12 by lgudin           ###   ########.fr       */
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
	val->p_mod = CONIQUE; 
}
void    ft_init(t_fdf *env)
{
    val_init(env->val);
    ptr_init(&env->ptr);
    env->stat_mode = REG_S;
}