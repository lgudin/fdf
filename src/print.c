/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/07 18:41:06 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_fdf *env, float x, float y,t_rgb color)
{
    if ( x <= LARGEUR && x >= 0 && y <= HAUTEUR && y >= 0 && ((x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line) + 3) < HAUTEUR * LARGEUR * 4)
    {
        env->ptr.img_data[(int)((x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line))] = color.color_r;
        env->ptr.img_data[(int)((x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line) + 1)] = color.color_g;
        env->ptr.img_data[(int)((x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line) + 2)] = color.color_b;
    }
}

void    set_square(t_cursor p_one, t_cursor p_two,t_fdf *env, int color)
{
    t_cursor c;

    c.y = p_one.y;
    while (c.y < p_two.y && c.y < env->width->y)
    {
        c.x = p_one.x;
        while (c.x < p_two.x && c.x < env->width->x)
        {
            ft_put_pixel(env, (float)c.x, (float)c.y, hex_to_rgb(color));
            c.x++;
        }
        c.y++;
    }
}

void    fill_image(t_fdf *env)
{
    t_cursor c;

    c.y = -1;
    while (++c.y < env->width->y)
    {
        c.x = -1;
        while (++c.x < env->width->x)
        {
            if(c.x + 1< env->width->x)
            {
               draw_line(env, env->proj[c.y][c.x], env->proj[c.y][c.x + 1]);
            }
            if (c.y + 1 < env->width->y)
            {
                draw_line(env, env->proj[c.y][c.x], env->proj[c.y + 1][c.x]);
            }
        }
    }
}