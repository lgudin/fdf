/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:03:37 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/09 10:20:37 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    derive_fdf_main(t_fdf *env)
{
    env->layout->x = 0;
    env->layout->y = 0;
    env->dir = BAS_GAUCHE;
    env->borne = ft_get_borne(env->proj, env->width);
    
    ft_putstrln("derive fdf main");
    
    while (env->stat_mode == LOCK_S)
    {
        mlx_hook(env->ptr.win, 2, 3, derive_fdf, env);
        if (ft_boing(env))
            env->lock_color = hex_to_rgb(lock_color_switch());
        ft_ca_bouge(env);
        ft_expose_hook(env);
    }
}

int   derive_fdf(int keycode, t_fdf *env)
{
    if (keycode == L)
        env->stat_mode = REG_S;
    else if (keycode == ESC)
        exit(0);
    else
        ft_putstrln("PRESS L TO LEAVE THE LOCKSCREEN MODE");
    return (1);
}

int    lock_color_switch(void)
{
    static int count = 0;

    if (count++ == 0)
        return (OLD_GREEN);
    else if (count++ == 1)
        return(OLD_BLUE);
    else if (count++ == 2)
        return(OLD_PINK);
    else if (count++ == 3)
        return (OLD_PURPLE);
    else 
    {
        count = 0;
        return (OLD_ORANGE);
    }
    ft_putstrln("Error : lock_color_switch");
    return(WHITE);
}

void    ft_ca_bouge(t_fdf *env)
{
    if (env->dir == BAS_GAUCHE)
    {
        env->layout->x++;
        env->layout->y++;
    }
    else if (env->dir == BAS_DROIT)
    {
        env->layout->x--;
        env->layout->y++;
    }
    else if (env->dir == HAUT_GAUCHE)
    {
        env->layout->x++;
       env->layout->y--;
    }
    else if (env->dir == HAUT_DROIT)
    {
        env->layout->x--;
        env->layout->y--;
    }
}

int ft_boing(t_fdf *env)
{
    if (env->borne.x + env->layout->x >= LARGEUR) // si on touche la droite
    {
        env->dir = env->dir == BAS_DROIT ? BAS_GAUCHE : HAUT_GAUCHE;
        return (1);
    }
    else if (env->borne.x + env->layout->x <= 0)
    {
        env->dir = env->dir == BAS_GAUCHE ? BAS_DROIT : HAUT_DROIT;   
        return (1);
    }
    else if (env->borne.y + env->layout->y >= HAUTEUR)
    {   
        env->dir = env->dir == BAS_DROIT ? HAUT_GAUCHE : HAUT_DROIT;
        return (1);
    }
    else if(env->borne.y + env->layout->y <= 0)
    {
        env->dir = env->dir == HAUT_DROIT ? BAS_GAUCHE : BAS_DROIT;
        return (1);
    }
    return (0);
}

t_cursor    ft_get_borne(t_proj **proj, t_cursor *width)
{
    t_cursor borne;
    t_cursor c;

    c.y = 0;
    while (c.y < width->y - 1)
    {
        proj[c.y][width->x - 1].x < borne.x ? borne.x = proj[c.y][width->x - 1].x : 0;
        c.y++;  
    }
    c.x = 0;
    while (c.x < width->x -1)
    {
        proj[width->y - 1][c.x].y < borne.y ? borne.y = proj[width->y - 1][c.x].y : 0;
        c.x++;
    }
    return (borne);
}
