/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 19:38:27 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(void)
{
	ft_putstrln("error");
	return (1);
}

void projection_tintintin(t_proj **proj, t_pt **tab, t_cursor *width, t_event *val)
{
    int y;
    int x;

    y = 0;
    while (y < width->y)
    {
        x = 0;
        while (x < width->x)
        {
            proj[y][x].x = (((tab[y][x].x * val->size) - tab[y][x].y * val->size) * cos(0.523599) + (1920/ 2)) + val->x; // 0.523599
            proj[y][x].y = (-(tab[y][x].z * val->size) + ((tab[y][x].x + tab[y][x].y) * val->size) * sin(0.523599) + (1280 / 2)) + val->y;
            proj[y][x].color = set_color(tab[y][x], val);
            x++;
        }
        y++;
    }
}

int main(__unused int ac, char **av)
{
    t_ptr       ptr;
    t_pt        **tab;
    t_proj      **proj;
    t_cursor    *width;
    t_event     *val;

    tab     = NULL;
    proj    = NULL;

    if (!(width = (t_cursor*)malloc(sizeof(t_cursor))))
        return (0);

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1920, 1280, "On fait pas fdf nous ??");

    if (!(tab = ft_read_points(av[1], tab, width)))
        return (ft_error());
    ft_putstrln("read passed");
    
    if (!(proj = proj_tab_malloc(proj, width)))
        return(ft_error());
    ft_putstrln("proj tab malloc passed");

    set_full_map(ptr, width, BLACK);
    ft_putstrln("Map salement recouverte");

    projection_tintintin(proj, tab, width, val);
    ft_putstrln("Traitement passed");
    
    print_map(proj, ptr, width);
    ft_putstrln("print passed");

    mlx_hook(ptr.win, 2, 3, ft_key_hook, (void*)0);
	//mlx_expose_hook(ptr.win, ft_expose_hook, ptr);

    mlx_loop(ptr.mlx);
    return (0);
}
//gcc -g -I /usr/local/include ./src/*.c ../libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra -fsanitize=address