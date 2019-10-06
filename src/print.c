/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 19:29:34 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    set_full_map(t_ptr ptr, int color)
{
    t_cursor c;
    
    c.y = 0;
    while (c.y < HAUTEUR)
    {
        c.x = 0;
        while (c.x < LARGEUR)
        {
            mlx_pixel_put(ptr.mlx, ptr.win,c.x, c.y, color);
            c.x++;
        }
        c.y++;
    }
}

void    print_map(t_proj **map, t_ptr ptr, t_cursor *width)
{
    (void)ptr;
    t_cursor c;

    c.y = -1;
    while (++c.y < width->y)
    {
        c.x = -1;
        while (++c.x < width->x)
        {
            if(c.x + 1< width->x)
            {
               draw_line(map[c.y][c.x], map[c.y][c.x + 1], ptr);
            }
            if (c.y + 1 < width->y)
            {
                draw_line(map[c.y][c.x], map[c.y + 1][c.x], ptr);
            }
        }
    }
}
