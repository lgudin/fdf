/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:23 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/22 15:12:03 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_error(char *s)
{
	ft_putstr("Error: ");
	ft_putstrln(s);
	return ((void*)NULL);
}

int		main(int ac, char **av)
{
	t_fdf	*env;

	if (ac != 2)
		return ((int)ft_error(" Usages : ./fdf [Source_file]"));
	if (!(env = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return ((int)ft_error("Malloc env"));
	if (!(env->width = (t_cursor*)ft_memalloc(sizeof(t_cursor))))
		return ((int)ft_error("Malloc env.width"));
	if (!(env->val = (t_event*)ft_memalloc(sizeof(t_event))))
		return ((int)ft_error("Malloc env->val"));
	env->val->init_color = INIT_COLOR;
	ft_init(env);
	if (!(env->tab = ft_read_points(av[1], env->tab, env->width)))
		return ((int)ft_error("ft_read_points"));
	ft_init_game(env);
	env->val->size = (LARGEUR + HAUTEUR) / 2 / env->width->x;
	if (!(env->proj = proj_tab_malloc(env->proj, env->width)))
		return ((int)ft_error("proj_tab malloc"));
	mlx_hook(env->ptr.win, 2, 3, ft_key_hook, env);
	mlx_expose_hook(env->ptr.win, ft_expose_hook, env);
	mlx_loop(env->ptr.mlx);
	return (0);
}
