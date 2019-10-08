/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:03:37 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/08 18:00:11 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    derive_fdf_main(t_fdf *env)
{
    enum dir dir;
    
    dir = BAS_GAUCHE;
    env->borne = ft_get_borne(env->proj, env->width);
    
    ft_putstrln("derive fdf main");
    
    while (env->stat_mode == LOCK_S)
    {
        mlx_hook(env->ptr.win, 2, 3, derive_fdf, env);
        if (ft_boing(&dir, env, env->borne))
            env->lock_color = hex_to_rgb(lock_color_switch());
        ft_ca_bouge(dir, env);
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

void    ft_ca_bouge(enum dir dir, t_fdf *env)
{
    if (dir == BAS_GAUCHE)
    {
        env->layout->x++;
        env->layout->y++;
    }
    else if (dir == BAS_DROIT)
    {
        env->layout->x--;
        env->layout->y++;
    }
    else if (dir == HAUT_GAUCHE)
    {
        env->layout->x++;
       env->layout->y--;
    }
    else if (dir == HAUT_DROIT)
    {
        env->layout->x--;
        env->layout->y--;
    }
}

int ft_boing(enum dir *dir, t_fdf *env, t_cursor borne)
{
    if (borne.x + env->layout->x >= LARGEUR) // si on touche la droite 
    {
        *dir = (*dir == BAS_DROIT ? BAS_GAUCHE : HAUT_GAUCHE);
        return (1);
    }
    else if (borne.x + env->layout->x <= 0)
    {
        *dir = (*dir == BAS_GAUCHE ? BAS_DROIT : HAUT_DROIT);
        return (1);
    }
    else if (borne.y + env->layout->y >= HAUTEUR)
    {
        *dir = (*dir == BAS_DROIT ? HAUT_GAUCHE : HAUT_DROIT);
        return (1);
    }
    else if(borne.y + env->layout->y <= 0)
    {
        *dir = (*dir == HAUT_DROIT ? BAS_GAUCHE : BAS_DROIT);
        return (1);
    }
    return (0);
}

t_cursor    ft_get_borne(t_proj **proj, t_cursor *width)
{
    t_cursor borne;
    t_cursor c;

    c.y = 0;
    while (c.y < width->y)
    {
        proj[c.y][width->x].x < borne.x ? borne.x = proj[c.y][width->x].x : 0;
        c.y++;
    }
    c.x = 0;
    while (c.x < width->x)
    {
        proj[width->y][c.x].y < borne.y ? borne.y = proj[width->y][c.x].y : 0;
        c.x++;
    }
    return (borne);
}
