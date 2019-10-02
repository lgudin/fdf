/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/02 20:38:25 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham(int x1, int y1, int x2, int y2, int *win_ptr, int *mlx_ptr, int color) 
{ 
   int m_new = 2 * (y2 - y1); 
   int slope_error_new = m_new - (x2 - x1); 
   for (int x = x1, y = y1; x <= x2; x++) 
   { 
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x555555);
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error. 
      if (slope_error_new >= 0) 
      { 
         y++; 
         slope_error_new  -= 2 * (x2 - x1); 
      } 
   } 
} 

void    print_map(t_pt **map, t_ptr ptr, int width)
{
    t_cursor c;

    c.y = -1;
    while (++c.y < 10)
    {
        c.x = -1;
        while (++c.x< 17)
        {
            if(map[c.y][c.x].x < 17)
            {
                printf("trait de [%d ,%d] a [%d ,%d]\n ", map[c.y][c.x].x * 20, map[c.y][c.x].y * 20, map[c.y][c.x + 1].x * 20, map[c.y][c.x + 1].y * 20);
                //bresenham(map[c.y][c.x].x * 20,map[c.y][c.x].y * 20, map[c.y][c.x + 1].x * 20, map[c.y][c.x + 1].y * 20, ptr.win, ptr.mlx, map[c.y][c.x].color);
            }
            else if (map[c.y][c.x].y < 10)
            {
                printf("trait de [%d ,%d] a [%d ,%d]\n ",map[c.y][c.x].x * 20,map[c.y][c.x].y * 20, map[c.y + 1][c.x].x * 20, map[c.y + 1][c.x].y * 20);
                //bresenham(map[c.y][c.x].x * 20,map[c.y][c.x].y * 20, map[c.y + 1][c.x].x * 20, map[c.y + 1][c.x].y * 20, ptr.win, ptr.mlx, map[c.y][c.x].color);
            }
        }
    }

}
int main(int ac, char **av)
{
    t_ptr ptr;
    t_pt **tab;
    int width;
    
    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 500, 500, "On fait pas fdf nous ??");
    ft_putstrln("Passed ?");
    width = ft_read_points(av[1], tab);
    ft_putstrln("read passed");
    print_map(tab, ptr, width);
    ft_putstrln("printed map");
    mlx_loop(ptr.mlx);

}