/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/10 10:16:21 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(char *s)
{
	ft_putstr("error :");
    ft_putstrln(s);
	return (1);
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
    ft_init(env);


    env->ptr.mlx = mlx_init();
    env->ptr.win = mlx_new_window(env->ptr.mlx, LARGEUR, HAUTEUR, "On fait pas fdf nous ??");

    if (!(env->tab = ft_read_points(av[1], env->tab, env->width)))
        return (ft_error("ft_read_points"));
    
    env->val->size = LARGEUR / ((env->width->x > env->width->y ? env->width->x : env->width->y) + 1);
    
    if (!(env->proj = proj_tab_malloc(env->proj, env->width)))
        return(ft_error("proj_tab malloc"));
    mlx_hook(env->ptr.win, 1L<<5, 0 , ft_key_hook, env);
    mlx_hook(env->ptr.win, 2, 3, ft_key_hook, env);
	mlx_expose_hook(env->ptr.win, ft_expose_hook,env); // ft qui reprint ?
    mlx_loop(env->ptr.mlx);
    return (0);
}