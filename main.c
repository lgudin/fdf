/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/03 21:58:59 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(void)
{
	ft_putstrln("error");
	return (1);
}

void    print_map(t_pt **map, t_ptr ptr, t_cursor *width)
{
    (void)ptr;
    t_cursor c;

    c.y = -1;
    ft_putstrln("hA");
    while (++c.y < width->y)
    {
        ft_putstrln("hB");
        c.x = -1;
        while (++c.x < width->x)
        {
            ft_putstrln("hC");
            if(c.x + 1< width->x)
            {
                ft_putstrln("if 1");
                // draw_line(LAYOUT + map[c.y][c.x].x * SIZE, LAYOUT + map[c.y][c.x].y * SIZE, LAYOUT + map[c.y][c.x + 1].x * SIZE, LAYOUT + map[c.y][c.x + 1].y * SIZE, ptr.win, ptr.mlx,0x550000);
               // printf("trait de [%d ,%d] a [%d ,%d]\n ", map[c.y][c.x].x * , map[c.y][c.x].y * 20, map[c.y][c.x + 1].x * 20, map[c.y][c.x + 1].y * 20);
               draw_line(map[c.y][c.x], map[c.y][c.x + 1], ptr);
            }
            if (c.y + 1 < width->y)
            {
                ft_putstrln("if 2");
               // printf("trait de [%d ,%d] a [%d ,%d]\n ",map[c.y][c.x].y * SIZE,map[c.y][c.x].x * SIZE, map[c.y + 1][c.x].x * SIZE, map[c.y + 1][c.x].y * SIZE);
               //draw_line(LAYOUT + map[c.y][c.x].x * SIZE/**/ , LAYOUT + map[c.y][c.x].y * SIZE, /**/LAYOUT +  map[c.y + 1][c.x].x * SIZE,/**/ LAYOUT + map[c.y + 1][c.x].y * SIZE + 50,/**/ ptr.win, ptr.mlx, 0x555555);
                draw_line(map[c.y][c.x], map[c.y + 1][c.x], ptr);
            }
        }
    }
    ft_putstr("ok ?");
    //bresenham(150,0,155,100, ptr.win, ptr.mlx,0x550000);
    ft_putstr("ok !");

}

void projection_tintintin(t_pt **tab, t_cursor *width)
{
    int y;
    int x;

    y = 0;
    while (y < width->y)
    {
        x = 0;
        while (x < width->x)
        {
            tab[y][x].x = ((tab[y][x].x - tab[y][x].y) * cos(0.45) + (1500 / 2)); // 0.523599
            tab[y][x].y = (-tab[y][x].z + (tab[y][x].x + tab[y][x].y) * sin(0.5) + (1500 / 2));
            x++;
        }
        y++;
    }
}

int main(__unused int ac, char **av)
{
    t_ptr ptr;
    t_pt **tab;
    t_cursor *width;

    tab = NULL;
    width = NULL;
    if (!(width = (t_cursor*)malloc(sizeof(t_cursor))))
        return (0);
    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1500, 1500, "On fait pas fdf nous ??");
    ft_putstrln("PassedTTT ?");
    if (!(tab = ft_read_points(av[1], tab, width)))
        return (ft_error());
    projection_tintintin(tab, width);
    ft_putstrln("read passed");
     //printf("%d ",tab[0][0].x );
    print_map(tab, ptr, width);
    ft_putstrln("printed map");
    mlx_loop(ptr.mlx);
    return (0);
}