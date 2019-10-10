/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:06:54 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/10 15:08:13 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_rgb    hex_to_rgb(int hex_color)
{
    t_rgb splitted_color;
    
    splitted_color.color_r = hex_color %256;
	hex_color /= 256;
	splitted_color.color_g = hex_color% 256;
	hex_color /= 256;
	splitted_color.color_b = hex_color% 256;
    return (splitted_color);
}

int    set_color(t_pt tab, t_event *val)
{
    if (val->color_mode == REGULAR)
        return (val->init_color);
    else if (val->color_mode == MAP)
        return (color_set_mode_map(tab.z * val->alti));
    else if (val->color_mode == EGYPTIAN)
        return (SAND);
    else if (val->color_mode == VAPORWAVE)
        return (color_set_mode_vaporwave(tab.z + val->alti));
    else if (val->color_mode == DVD)
        return(color_set_mode_dvd(tab.z));
    ft_putstrln("ERROR : mode de couleur non implementé dans color_set.c");
    return (WHITE);
}

void	dvd_color_set(t_fdf *env)
{
	t_cursor c;
	int color;

	c.y = -1;
	color = lock_color_switch();
	while (++c.y < env->width->y)
	{
		c.x = -1;
		while (++c.x < env->width->x)
			env->proj[c.y][c.x].color =
			hex_to_rgb(set_color(env->tab[c.y][c.x], env->val) == BLACK ?
			 set_color(env->tab[c.y][c.x], env->val) : color );
	}
}

