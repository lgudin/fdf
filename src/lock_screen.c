/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:03:37 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/21 17:20:15 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		lock_color_switch(void)
{
	static int count = -1;

	count++;
	if (count == 0)
		return (OLD_GREEN);
	else if (count == 1)
		return (OLD_BLUE);
	else if (count++ == 2)
		return (OLD_PINK);
	else if (count++ == 3)
		return (OLD_PURPLE);
	else
	{
		count = -1;
		return (OLD_ORANGE);
	}
	ft_putstrln("Error : lock_color_switch : count = -1 ?");
	return (WHITE);
}

void	ft_ca_bouge(t_fdf *env)
{
	if (env->dir == BAS_GAUCHE)
	{
		env->layout.x -= DVD_SPEED;
		env->layout.y += DVD_SPEED;
	}
	else if (env->dir == BAS_DROIT)
	{
		env->layout.x += DVD_SPEED;
		env->layout.y += DVD_SPEED;
	}
	else if (env->dir == HAUT_GAUCHE)
	{
		env->layout.x -= DVD_SPEED;
		env->layout.y -= DVD_SPEED;
	}
	else if (env->dir == HAUT_DROIT)
	{
		env->layout.x += DVD_SPEED;
		env->layout.y -= DVD_SPEED;
	}
}

int		ft_boing(t_fdf *env)
{
	if (env->borne.x + env->layout.x >= LARGEUR - DVD_SPEED)
	{
		env->dir = (env->dir == BAS_DROIT ? BAS_GAUCHE : HAUT_GAUCHE);
		return (1);
	}
	else if (env->borne_min.x + env->layout.x <= 0 + DVD_SPEED)
	{
		env->dir = (env->dir == BAS_GAUCHE ? BAS_DROIT : HAUT_DROIT);
		return (1);
	}
	else if (env->borne.y + env->layout.y >= HAUTEUR - DVD_SPEED)
	{
		env->dir = (env->dir == BAS_DROIT ? HAUT_DROIT : HAUT_GAUCHE);
		return (1);
	}
	else if (env->borne_min.y + env->layout.y <= 0 + DVD_SPEED)
	{
		env->dir = (env->dir == HAUT_DROIT ? BAS_DROIT : BAS_GAUCHE);
		return (1);
	}
	return (0);
}

int		ft_get_borne(t_fdf *env)
{
	t_cursor c;

	c.y = 0;
	c.x = 0;
	env->borne_min.y = HAUTEUR;
	env->borne_min.x = LARGEUR;
	env->borne.y = 0;
	env->borne.x = 0;
	while (c.y < env->width->y)
	{
		if (env->proj[c.y][0].x < env->borne_min.x)
			env->borne_min.x = env->proj[c.y][0].x;
		if (env->proj[c.y][env->width->x - 1].x > env->borne.x)
			env->borne.x = env->proj[c.y][env->width->x - 1].x;
		c.y++;
	}
	while (c.x < env->width->x)
	{
		if (env->proj[0][c.x].y < env->borne_min.y)
			env->borne_min.y = env->proj[0][c.x].y;
		if (env->proj[env->width->y - 1][c.x].y > env->borne.y)
			env->borne.y = env->proj[env->width->y - 1][c.x].y;
		c.x++;
	}
	return (1);
}

int		ft_is_inside(t_fdf *env)
{
	if (env->borne.x + env->layout.x - DVD_SPEED >= LARGEUR ||
		env->borne_min.x + env->layout.x + DVD_SPEED <= 0 ||
		env->borne.y + env->layout.y - DVD_SPEED >= HAUTEUR ||
		env->borne_min.y + env->layout.y + DVD_SPEED <= 0)
		return (0);
	else
		return (1);
}
