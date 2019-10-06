/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:06:54 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 19:28:16 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_rgb    hex_to_rgb(int hex_color, t_rgb splitted_color)
{
    splitted_color.color_b = hex_color %256;
	hex_color /= 256;
	splitted_color.color_g = hex_color% 256;
	hex_color /= 256;
	splitted_color.color_r = hex_color% 256;
    return (splitted_color);
}

int    set_color(t_pt tab, t_event *val)
{
    if (val->color_mode == REGULAR)
        return (tab.color);
    else if (val->color_mode == MAP)
    {
        return (color_set_map(tab.z));
    }
    else if (val->color_mode == EGYPTIAN)
    {
        return (SAND);
    }
    else if (val->color_mode == VAPORWAVE)
    {
        return (color_set_vaporwave(tab.z));
    }
    ft_putstrln("ERROR : pas de mode de couleur detecté");
    return (tab.color);
}

int     color_set_vaporwave(float z)
{
    if (z < 1)
    {
        return (VAPOR_BLUE);
    }
    else
    {
        return (VAPOR_PINK);
    }
    
}
int     color_set_map(float z)
{
    if (z < -5)
        return (DEEP_BLUE);
    else if (z < 0)
        return (BLUE);
    else if (z < 5)
        return (GRASSE);
    else
        return (WHITE);
}