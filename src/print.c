/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/09 18:43:41 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y,t_rgb color)
{
    int calculation;

    calculation = (x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line);
    printf("%d ", calculation);
    if (env->stat_mode == LOCK_S)
    {
        x += env->layout.x;
        y += env->layout.y;
        color = env->lock_color;
    }
    calculation = (x * (env->ptr.bpp / 8)) + (y * env->ptr.size_line);
    printf("%d\n", calculation);
    if ( x <= LARGEUR && x >= 0 && y <= HAUTEUR && y >= 0 && calculation + 3 < HAUTEUR * LARGEUR * 4) // SECURITE INT MAX
    {
        //ft_putchar('a');
        env->ptr.img_data[calculation] = color.color_r;
        env->ptr.img_data[calculation + 1] = color.color_g;
        env->ptr.img_data[calculation + 2] = color.color_b;
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
            ft_put_pixel(env, c.x, c.y, hex_to_rgb(color));
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