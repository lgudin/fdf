/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 19:33:20 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    set_full_map(t_ptr ptr, t_cursor *width, int color)
{
    (void)ptr;
    t_proj point_zero;
    t_proj point_one;

    point_one.color = color;
    point_zero.color = color;
    point_one.x = width->x;
    point_zero.x = 0;
    point_zero.y = -1;
    point_one.y = -1;

    while (++point_zero.y < width->y)
    {
        ++point_one.y;
        draw_line(point_zero, point_one, ptr);
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
