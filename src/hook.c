/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 11:44:30 by lgudin           ###   ########.fr       */
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
		ft_key_hook_reset(env->val);

	// reste à actualiser : del / reprint
	 // ft_expose_hook(fdf);

	 // SANS IMAGE ca donne :
	 projection_tintintin(env);
	 set_full_map(env->ptr, env->width, BLACK);
	 print_map(env->proj, env->ptr, env->width);
	return (0);
}

void	ft_key_hook_reset(t_event *val)
{
	val->x = 0;
	val->y = 0;
	val->size = 0;
	val->alti = 0;
	val->color = REGULAR;
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

// ce qu'on doit faire  : 

/*int	ft_expose_hook(t_ptr ptr)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_length, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}
*/