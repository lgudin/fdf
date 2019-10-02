/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/02 13:05:57 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

void    print_map(struct_map **map, )
{

}
int main(int ac, char **av)
{
    int *mlx_ptr;
    int *win_ptr;
    t_pix pix;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "On fait pas fdf nous ??");
    bresenham(pix.x, pix.y, atoi(av[3]), atoi(av[4]), win_ptr, mlx_ptr, 0x505050);
    mlx_loop(mlx_ptr);

}