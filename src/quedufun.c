/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quedufun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:04:47 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 09:49:51 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    ft_init_game(t_fdf *env)
{
    env->player_c.y = 0;
    env->player_c.x = 0;
    ft_find_start(env);
}

void    ft_move_down(t_fdf *env)
{
    ft_del_around(env);
    env->player_c.y++;
    if (ft_check_around(env))
    {
        env->player_c.y--;
        ft_del_around(env);
        env->player_c.y++;
        ft_put_around(env);
    }
    else
    {
         env->player_c.y--;
         ft_put_around(env);
    }

}

void    ft_move_up(t_fdf *env)
{
    ft_del_around(env);
    env->player_c.y--;
     if (ft_check_around(env))
    {
        env->player_c.y++;
        ft_del_around(env);
        env->player_c.y--;
        ft_put_around(env);
    }
    else
    {
        env->player_c.y++;
        ft_put_around(env);
    }
}

void    ft_move_left(t_fdf *env)
{
    ft_del_around(env);
    env->player_c.x--;
    if (ft_check_around(env))
    {
        env->player_c.x++;
        ft_del_around(env);
        env->player_c.x--;
        ft_put_around(env);
    }
    else
    {
        env->player_c.x++;
        ft_put_around(env);
    }
}

void    ft_move_right(t_fdf *env)
{
    ft_del_around(env);
    env->player_c.x++;
     if (ft_check_around(env))
    {
        env->player_c.x--;
        ft_del_around(env);
        env->player_c.x++;
        ft_put_around(env);
    }
    else
    {
        env->player_c.x--;
        ft_put_around(env);
    }
}

void ft_find_start(t_fdf *env)
{
    while (!(ft_check_around(env) == 1) && env->player_c.x < env->width->x)
        env->player_c.x++;
}

int ft_is_win(t_fdf *env)
{
    if (env->player_c.y + 1 >= (env->width->y - 1))
        return (1);
    return (0);
}

int    ft_check_around(t_fdf *env)
{
    if (env->player_c.y >= 0 && env->player_c.y + 1 < env->width->y
    &&   env->player_c.x - 1>= 0 && 
      env->player_c.x < env->width->x &&
       env->tab[env->player_c.y][env->player_c.x].z == 0 &&
        env->tab[env->player_c.y][env->player_c.x - 1].z == 0 &&
         env->tab[env->player_c.y + 1][env->player_c.x].z == 0 &&
          env->tab[env->player_c.y + 1 ][env->player_c.x - 1].z == 0)
        return (1);
    else
        return (0);
}

void    ft_del_around(t_fdf *env)
{
    env->tab[env->player_c.y][env->player_c.x].z = 0;
    env->tab[env->player_c.y][env->player_c.x - 1].z = 0;
    env->tab[env->player_c.y + 1][env->player_c.x].z = 0;
    env->tab[env->player_c.y + 1][env->player_c.x - 1].z = 0;
}

void    ft_put_around(t_fdf *env)
{
    env->tab[env->player_c.y][env->player_c.x].z = PLAYER_HEIGHT;
    env->tab[env->player_c.y][env->player_c.x - 1].z = PLAYER_HEIGHT;
    env->tab[env->player_c.y + 1][env->player_c.x].z = PLAYER_HEIGHT;
    env->tab[env->player_c.y + 1][env->player_c.x - 1].z = PLAYER_HEIGHT;
}