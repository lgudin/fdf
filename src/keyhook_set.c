/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:10:56 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 15:39:29 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_hook_proj_mode(t_event *val)
{
	if (val->p_mod == CONIQUE)
		val->p_mod = PARA;
	else
		val->p_mod = CONIQUE;
}

void	ft_key_hook_move(int keycode, t_fdf *env)
{
	if (keycode == RIGHT_ARROW)
		env->val->x += MOVE_SPEED * ((LARGEUR + HAUTEUR / 2) / 200);
	else if (keycode == LEFT_ARROW)
		env->val->x -= MOVE_SPEED * ((LARGEUR + HAUTEUR / 2) / 200);
	else if (keycode == UP_ARROW)
		env->val->y -= MOVE_SPEED * ((LARGEUR + HAUTEUR / 2) / 200);
	else if (keycode == DOWN_ARROW)
		env->val->y += MOVE_SPEED * ((LARGEUR + HAUTEUR / 2) / 200);
}

void	ft_key_hook_color_mode(t_event *val)
{
	val->color_mode++;
	if (val->color_mode == LAST)
		val->color_mode = 0;
}

void	ft_key_hook_alti(int keycode, t_event *val)
{
	if (keycode == MORE && val->alti < 2147483647 - ALTI_SPEED
		&& val->alti > -2147483648 + ALTI_SPEED)
		val->alti += ALTI_SPEED;
	else
		val->alti -= ALTI_SPEED;
}

void	ft_key_hook_zoom(int keycode, t_event *val)
{
	if (keycode == I && val->size < ((HAUTEUR + LARGEUR) / 2) && ZOOM_SPEED > 1)
		val->size *= ZOOM_SPEED;
	else if (keycode == O && val->size > 0.01 && ZOOM_SPEED > 1)
		val->size /= ZOOM_SPEED;
}
