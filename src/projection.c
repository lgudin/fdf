/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:19:26 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/10 10:20:48 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void projection_para(t_fdf *env)
{
    int y;
    int x;

    y = 0;
    while (y < env->width->y)
    {
        x = 0;
        while (x < env->width->x)
        {
            env->proj[y][x].x = env->tab[y][x].x * env->val->size
                + env->val->x + env->val->size;
            env->proj[y][x].y = env->tab[y][x].y * env->val->size
                + env->val->y + env->val->size;
            env->proj[y][x].color = 
                hex_to_rgb(set_color(env->tab[y][x], env->val));
            x++;
        }
        y++;
    }
}

void projection_tintintin(t_fdf *env)
{
    int y;
    int x;

    y = 0;
    while (y < env->width->y)
    {
        x = 0;
        while (x < env->width->x)
        {
            env->proj[y][x].x = (((env->tab[y][x].x * env->val->size) 
                - env->tab[y][x].y * env->val->size) * cos(0.523599))
                    + env->val->x + env->val->size;
            env->proj[y][x].y = (-((env->tab[y][x].z * env->val->size)
                * env->val->alti) + ((env->tab[y][x].x + env->tab[y][x].y)
                    * env->val->size) * sin(0.523599))
                        + env->val->y + env->val->size;
            env->proj[y][x].color = hex_to_rgb(set_color(env->tab[y][x],
                env->val));
            x++;
        }
        y++;
    }
}