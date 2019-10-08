/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:03:37 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/08 13:21:55 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    derive_fdf_main(t_fdf *env)
{
    while (env->stat_mode == LOCK_S)
    {
        mlx_hook(env->ptr.win, 2, 3, derive_fdf, env);
    }
}

int    derive_fdf(int keycode, t_fdf *env)
{
    t_cursor c;

    c.x = 0;
    c.y = 0;
    enum dir dir;

    dir = BAS_GAUCHE;

}

int ft_ca_bouge(enum dir dir, t_fdf *env)
{
 if (dir == BAS_GAUCHE)
    {
        env->val->x++;
        env->val->y++;
    }
    else if (dir == BAS_DROIT)
    {
        env->val->x--;
        env->val->y++;
    }
    else if (dir == HAUT_GAUCHE)
    {
        env->val->x++;
       env->val->y--;
    }
    else if (dir == HAUT_DROIT)
    {
        env->val->x--;
        env->val->y--;
    }
}

int ft_boing(enum dir dir, t_fdf *env)
{
    if (env->proj[0][env->width->x].x >= env->width->x) // si on touche la doite 
    {
        // ( verif à faire : angle ?? ) juste à la gestion de couleur en soit 
        dir = (dir == BAS_DROIT ? BAS_GAUCHE : HAUT_GAUCHE);
        // changement de couleur ?? kl
    }
    else if (env->val->x <= 0)
    {
        dir = (dir == BAS_GAUCHE ? BAS_DROIT : HAUT_DROIT);
    }
    else if (env->val->y >= env->width->y)
    {
        dir = (dir == BAS_DROIT ? HAUT_GAUCHE : HAUT_DROIT);
    }
    else if(env ->val->y <= 0)
    {
        dir = (dir == HAUT_DROIT ? BAS_GAUCHE : BAS_DROIT);
    }
}

void    launch_derive(enum dir dir, t_fdf *env)
{
    t_cursor c;
    dir = BAS_GAUCHE;
    
    c.y = 0;
    c.x = 0;

    if (env->proj[c.y][c.x].x + 1 < env->width->x && env->proj[c.y][c.x].y + 1 )
    {
        env->proj[c.y][c.x].x++;
        env->proj[c.y][c.x].y++;
    }
    else if 
}