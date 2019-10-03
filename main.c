/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/03 14:18:43 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(void)
{
	ft_putstrln("error");
	return (1);
}

void bresenham(int x1, int y1, int x2, int y2, int *win_ptr, int *mlx_ptr, int color) 
{ 
   int m_new = 2 * (y2 - y1); 
   int slope_error_new = m_new - (x2 - x1); 
   for (int x = x1, y = y1; x <= x2; x++) 
   { 
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
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
                //printf("trait de [%d ,%d] a [%d ,%d]\n ", map[c.y][c.x].x * 20, map[c.y][c.x].y * 20, map[c.y][c.x + 1].x * 20, map[c.y][c.x + 1].y * 20);
               bresenham(LAYOUT + map[c.y][c.x].x * SIZE, LAYOUT + map[c.y][c.x].y * SIZE, LAYOUT + map[c.y][c.x + 1].x * SIZE, LAYOUT + map[c.y][c.x + 1].y * SIZE, ptr.win, ptr.mlx,0x550000);
            }
            if (c.y + 1 < width->y)
            {
                ft_putstrln("if 2");
                printf("trait de [%d ,%d] a [%d ,%d]\n ",map[c.y][c.x].y * SIZE,map[c.y][c.x].x * SIZE, map[c.y + 1][c.x].x * SIZE, map[c.y + 1][c.x].y * SIZE);

               bresenham(LAYOUT + map[c.y][c.x].x * SIZE/**/ , LAYOUT + map[c.y][c.x].y * SIZE, /**/LAYOUT +  map[c.y + 1][c.x].x * SIZE,/**/ LAYOUT + map[c.y + 1][c.x].y * SIZE,/**/ ptr.win, ptr.mlx, 0x555555);
            }
        }
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
    ft_putstrln("read passed");
     //printf("%d ",tab[0][0].x );
    print_map(tab, ptr, width);
    ft_putstrln("printed map");
    mlx_loop(ptr.mlx);
    return (0);
}