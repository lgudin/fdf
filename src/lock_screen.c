/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:03:37 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/09 18:46:33 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    derive_fdf_main(t_fdf *env)
{
    env->dir = BAS_GAUCHE;
    ft_get_borne(env);
    
    ft_putstrln("derive fdf main");
    while (env->stat_mode == LOCK_S)
    {
        printf("hello\n");
        //mlx_hook(env->ptr.win, 2, 3, derive_fdf, env);
        if (ft_boing(env))
            env->lock_color = hex_to_rgb(PINK);
        ft_ca_bouge(env);

    if (!(env->ptr.img = mlx_new_image(env->ptr.mlx, LARGEUR, HAUTEUR)))
		ft_error("mlx_new_image passe pas");
	env->ptr.img_data = mlx_get_data_addr(env->ptr.img, &env->ptr.bpp, &env->ptr.size_line,&env->ptr.endian);
    fill_image(env);
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
	sleep(1);
	mlx_destroy_image(env->ptr.mlx, env->ptr.img);
        //ft_expose_hook(env);
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
        env->layout.x -= 10;
        env->layout.y += 10;
    }
    else if (env->dir == BAS_DROIT)
    {
        env->layout.x += 10;
        env->layout.y += 10;
    }
    else if (env->dir == HAUT_GAUCHE)
    {
        env->layout.x -= 10;
       env->layout.y -= 10;
    }
    else if (env->dir == HAUT_DROIT)
    {
        env->layout.x += 10;
        env->layout.y -= 10;
    }
    ft_putstr("Layout max  x= ");
    ft_putnbr(env->layout.x + env->borne.x);
    ft_putchar('\n');
    ft_putstr("Layout  max y = ");
    ft_putnbr(env->layout.y + env->borne.y);
    ft_putchar('\n');
    ft_putstr("Layout min  x= ");
    ft_putnbr(env->layout.x + env->borne_min.x);
    ft_putchar('\n');
    ft_putstr("Layout  min y = ");
    ft_putnbr(env->layout.y + env->borne_min.y);
    ft_putchar('\n');
    ft_putchar('\n');
    
}

int ft_boing(t_fdf *env)
{
    if (env->borne.x + env->layout.x >= LARGEUR) // DROITE
    {
        env->dir = (env->dir == BAS_DROIT ? BAS_GAUCHE : HAUT_GAUCHE);
        ft_putstrln(" -> Boing droite");
        ft_putstrln(dir == BAS_GAUCHE ? "BAS GAUCHE" : "HAUT GAUCHE");
        return (1);
    }
    else if (env->borne_min.x + env->layout.x <= 0) // GAUCHE
    {
        env->dir = (env->dir == BAS_GAUCHE ? BAS_DROIT : HAUT_DROIT);
        ft_putstrln("Boing gauche");
        ft_putstrln(dir == BAS_DROIT ? "BAS DROIT" : "HAUT DROIT");
        return (1);
    }
    else if (env->borne.y + env->layout.y >= HAUTEUR) // BAS
    {   
        env->dir = (env->dir == BAS_DROIT ? HAUT_DROIT : HAUT_GAUCHE);
       ft_putstrln("Boing bas");
       ft_putstrln(dir == HAUT_GAUCHE ? "HAUT GAUCHE" : "HAUT DROIT");
        return (1);
    }
    else if(env->borne_min.y + env->layout.y <= 0) //HAUT
    {
        env->dir = (env->dir == HAUT_DROIT ? BAS_DROIT : BAS_GAUCHE);
    ft_putstrln("Boing haut");
    ft_putstrln(dir == BAS_DROIT ? "BAS DROIT" : "BAS GAUCHE");
        return (1);
    }
    return (0);
}

void    ft_get_borne(t_fdf *env)
{
    t_cursor c;

    c.y = 0;
    env->borne_min.y = HAUTEUR;
    env->borne_min.x = LARGEUR;
    
    while (c.y < env->width->y - 1)
    {
        if (env->proj[c.y][0].x < env->borne_min.x )
        {
            env->borne_min.x = env->proj[c.y][0].x;
        }
        if (env->proj[c.y][env->width->x - 1].x > env->borne.x )
        {
            env->borne.x = env->proj[c.y][env->width->x - 1].x;
        }
        c.y++;  
    }
    c.x = 0;
    while (c.x < env->width->x - 1)
    {
        if (env->proj[0][c.x].y < env->borne_min.y )
        {
            env->borne_min.y = env->proj[0][c.x].y;
        }
        if (env->proj[env->width->y - 1][c.x].y > env->borne.y )
        {
            env->borne.y = env->proj[env->width->y - 1][c.x].y;
        }
        c.x++;
    }
    ft_putstr("MIN X = ");
    ft_putnbr( env->borne_min.x);
    ft_putchar('\n');
    ft_putstr("MAX X = ");
    ft_putnbr( env->borne.x);
    ft_putchar('\n');
    ft_putstr("MIN Y = ");
    ft_putnbr( env->borne_min.y);
    ft_putchar('\n');
    ft_putstr("MAX Y = ");
    ft_putnbr( env->borne.y);
    ft_putchar('\n');
}
