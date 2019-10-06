/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 21:16:35 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int keycode, t_fdf *env)
{
    
	if (keycode == ESC)
		exit(0);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
			|| keycode == DOWN_ARROW || keycode == UP_ARROW)
		ft_key_hook_move(keycode, env->val);
	else if (keycode == I || keycode == O)
		ft_key_hook_zoom(keycode, env->val);
	else if (keycode == R)
		val_init(env->val, env->width);
	else if (keycode == LESS || keycode == MORE)
		ft_key_hook_alti(keycode, env->val);
	else if (keycode == C)
		ft_key_hook_color_mode(env->val);


	// reste à actualiser : del / reprint
	 // ft_expose_hook(fdf);

	 // SANS IMAGE ca donne :
	 set_full_map(env->ptr, BLACK);
	 projection_tintintin(env);
	 print_map(env->proj, env->ptr, env->width);
	return (0);
}

void	val_init(t_event *val, t_cursor *width)
{
	(void)width;
	val->x = 0;
	val->y = 0;
	val->size = INIT_SIZE;
	val->alti = INIT_ALTI;
	val->color_mode = REGULAR;
}
void	ft_key_hook_color_mode(t_event *val)
{
	if (val->color_mode < LAST)
		val->color_mode++;
	else if (val->color_mode == LAST)
		val->color_mode = 0;
}

void	ft_key_hook_alti(int keycode, t_event *val)
{
	if (keycode == MORE)
		val->alti+= ALTI_SPEED;
	else
		val->alti-= ALTI_SPEED;	
}

void	ft_key_hook_zoom(int keycode, t_event *val)
{
	if (keycode == I)
		val->size+= ZOOM_SPEED;
	else if (keycode == O)
		val->size-= ZOOM_SPEED;
}

void	ft_key_hook_move(int keycode, t_event *val)
{
	if (keycode == RIGHT_ARROW)
		val->x += (MOVE_SPEED * val->size);
	else if (keycode == LEFT_ARROW)
		val->x -= (MOVE_SPEED * val->size);
	else if (keycode == UP_ARROW)
		val->y -= (MOVE_SPEED* val->size);
	else if (keycode == DOWN_ARROW)
		val->y += (MOVE_SPEED * val->size);
}

int	ft_expose_hook(t_fdf *env)
{
	env->ptr.img = mlx_new_image(env->ptr.mlx, LARGEUR, HAUTEUR);
	env->ptr.img_data = mlx_get_data_addr(env->ptr.img, (int*)32, (int*)(LARGEUR * 4) /* LINE SIZE */ , (int*)0 /*ENDIAN ?? */);
	// IL FAUT L'EDIT CETTE PUTAIN D'IMAGE : convertir le ft_print 
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
	mlx_destroy_image(env->ptr.mlx, env->ptr.img);
	return (0);
}