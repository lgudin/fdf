/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 11:42:11 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(void)
{
	ft_putstrln("error");
	return (1);
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
            env->proj[y][x].x = (((env->tab[y][x].x * env->val->size) - env->tab[y][x].y * env->val->size) * cos(0.523599) + (1920/ 2)) + env->val->x; // 0.523599
            env->proj[y][x].y = (-(env->tab[y][x].z * env->val->size) + ((env->tab[y][x].x + env->tab[y][x].y) * env->val->size) * sin(0.523599) + (1280 / 2)) + env->val->y;
            env->proj[y][x].color = set_color(env->tab[y][x], env->val);
            x++;
        }
        y++;
    }
}

int main(__unused int ac, char **av)
{
    t_fdf   *env;

    env->tab     = NULL;
    env->proj    = NULL;
    env->val     = NULL;
    if (!(env->width = (t_cursor*)malloc(sizeof(t_cursor))))
        return (0);

    env->ptr.mlx = mlx_init();
    env->ptr.win = mlx_new_window(env->ptr.mlx, 1920, 1280, "On fait pas fdf nous ??");

    if (!(env->tab = ft_read_points(av[1], env->tab, env->width)))
        return (ft_error());
    ft_putstrln("read passed");
    
    if (!(env->proj = proj_tab_malloc(env->proj, env->width)))
        return(ft_error());
    ft_putstrln("proj tab malloc passed");

    set_full_map(env->ptr, env->width, BLACK);
    ft_putstrln("Map salement recouverte");

    projection_tintintin(env);
    ft_putstrln("Traitement passed");
    
    print_map(env->proj, env->ptr, env->width);
    ft_putstrln("print passed");

    mlx_hook(env->ptr.win, 2, 3, ft_key_hook, (void*)0);
	//mlx_expose_hook(ptr.win, ft_expose_hook, ptr);

    mlx_loop(env->ptr.mlx);
    return (0);
}
//gcc -g -I /usr/local/include ./src/*.c ../libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra -fsanitize=address