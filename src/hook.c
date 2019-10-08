/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/08 17:17:17 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int keycode, t_fdf *env)
{
    
	if (keycode == ESC)
		exit(0);
	else if (keycode == L || env->stat_mode == LOCK_S) // Tant qu'on unlock pas avec L on est bloqué sur ce mode
		ft_key_hook_screen_mode(env);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
			|| keycode == DOWN_ARROW || keycode == UP_ARROW)
		ft_key_hook_move(keycode, env);
	else if (keycode == I || keycode == O)
		ft_key_hook_zoom(keycode, env->val);
	else if (keycode == R)
		val_init(env->val);
	else if (keycode == LESS || keycode == MORE)
		ft_key_hook_alti(keycode, env->val);
	else if (keycode == C)
		ft_key_hook_color_mode(env->val);
	else if (keycode == A || keycode == D)
		ft_project_change(keycode, env);
	else if (keycode == TABULATION)
		ft_key_hook_proj_mode(env->val);
	ft_expose_hook(env);
	return (0);
}

void    ft_key_hook_screen_mode(t_fdf *env)
{
	env->stat_mode = LOCK_S;
	derive_fdf_main(env);
}

void	ft_key_hook_proj_mode(t_event *val)
{
	if (val->p_mod == CONIQUE)
		val->p_mod = PARA;
	else
		val->p_mod = CONIQUE;

}

void	ft_project_change(int keycode, t_fdf *env)
{
	if (keycode == A)
		env->val->wtf +=0.01;
	else if (keycode == D)
		env->val->wtf -=0.1;
}

void	val_init(t_event *val)
{
	val->x = 0;
	val->y = 0;
	val->alti = INIT_ALTI;
	val->color_mode = REGULAR;
}
void	ft_key_hook_color_mode(t_event *val)
{
	val->color_mode++;
	if (val->color_mode == LAST)
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
	if (keycode == I && val->size < ((HAUTEUR + LARGEUR)/ 2) && ZOOM_SPEED > 1)
		val->size*= ZOOM_SPEED;
	else if (keycode == O && val->size > 0.01 && ZOOM_SPEED > 1)
		val->size/= ZOOM_SPEED;
	printf("val->size = %f\n",val->size);
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

int	ft_expose_hook(t_fdf *env)
{
	if (!(env->ptr.img = mlx_new_image(env->ptr.mlx, LARGEUR, HAUTEUR)))
		return (ft_error("mlx_new_image passe pas"));
	env->ptr.img_data = mlx_get_data_addr(env->ptr.img, &env->ptr.bpp, &env->ptr.size_line,&env->ptr.endian);
	if (env->stat_mode == REG_S && env->val->p_mod == CONIQUE)
		projection_tintintin(env);
	else if	(env->stat_mode == REG_S && env->val->p_mod == PARA)
		projection_para(env);
	else if (!(env->stat_mode == LOCK_S)) 
		return(ft_error("Aucun mode de projection"));
	
	fill_image(env);
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
	mlx_destroy_image(env->ptr.mlx, env->ptr.img);
	return (0);
}