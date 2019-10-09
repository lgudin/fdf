/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/09 18:38:05 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(char *s)
{
	ft_putstr("error :");
    ft_putstrln(s);
	return (1);
}

void projection_para(t_fdf *env)
{
    int y;
    int x;

    y = 0;
    while (y < env->width->y)
    {
        x = 0;
        while (x < env->width->x)
        {
            env->proj[y][x].x = env->tab[y][x].x * env->val->size + env->val->x + env->val->size; // 0.523599
            env->proj[y][x].y = env->tab[y][x].y * env->val->size + env->val->y + env->val->size;
            env->proj[y][x].color = hex_to_rgb(set_color(env->tab[y][x], env->val));
            x++;
        }
        y++;
    }
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
            env->proj[y][x].x = (((env->tab[y][x].x * env->val->size) - env->tab[y][x].y * env->val->size) * cos(0.523599 * env->val->wtf)) + env->val->x + env->val->size; // 0.523599
            env->proj[y][x].y = (-((env->tab[y][x].z * env->val->size) * env->val->alti) + ((env->tab[y][x].x + env->tab[y][x].y) * env->val->size) * sin(0.523599 * env->val->wtf)) + env->val->y + env->val->size;
            env->proj[y][x].color = hex_to_rgb(set_color(env->tab[y][x], env->val));
            x++;
        }
        y++;
    }
}

int main(__unused int ac, char **av)
{
    t_fdf   *env;

    if (!(env = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
        return (ft_error("Malloc env"));
    if (!(env->width = (t_cursor*)ft_memalloc(sizeof(t_cursor))))
        return (ft_error("Malloc env.width"));
    if (!(env->val = (t_event*)ft_memalloc(sizeof(t_event))))
        return (ft_error("Malloc env->val"));

    env->ptr.endian = 0;
    env->ptr.bpp = 32;
    env->ptr.size_line = LARGEUR * 4;
    
    env->val->wtf = 1;
    env->val->angle = 0.5;

    env->layout.x = 0;
    env->layout.y = 0;

    env->borne.x = 0;
    env->borne.y = 0;

    env->stat_mode = REG_S;
    /*env->tab     = NULL;
    env->proj    = NULL;
    env->val     = NULL;
    */

    val_init(env->val);

    env->ptr.mlx = mlx_init();
    env->ptr.win = mlx_new_window(env->ptr.mlx, LARGEUR, HAUTEUR, "On fait pas fdf nous ??");
    

    if (!(env->tab = ft_read_points(av[1], env->tab, env->width)))
        return (ft_error("ft_read_points"));
    
    env->val->size = LARGEUR / ((env->width->x > env->width->y ? env->width->x : env->width->y) + 1);
    
    if (!(env->proj = proj_tab_malloc(env->proj, env->width)))
        return(ft_error("proj_tab malloc"));

   /* projection_tintintin(env);
    ft_putstrln("Traitement passed");
    
    print_map(env);
    ft_putstrln("print passed");
    */
    ft_putstr("AHEIN");
    mlx_hook(env->ptr.win, 2, 3, ft_key_hook, env);
	mlx_expose_hook(env->ptr.win, ft_expose_hook,env); // ft qui reprint ?
    //ft_expose_hook(env);

    mlx_loop(env->ptr.mlx);
    return (0);
}
//gcc -g -I /usr/local/include ./src/*.c ../libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra -fsanitize=address