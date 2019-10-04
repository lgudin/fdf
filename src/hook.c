/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 17:40:30 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int keycode, t_event val)
{
    
	if (keycode == ESC)
		exit(0);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
			|| keycode == DOWN_ARROW ||
			keycode == UP_ARROW)
		ft_key_hook_move(keycode, val);
	/*
	else if (keycode == MORE || keycode == LESS)
		ft_key_hook_alt(keycode, fdf);
	else if (keycode == ONE_NUM_PAD || keycode == TWO_NUM_PAD)
		ft_key_hook_zoom(keycode, fdf);
	else if (keycode == P)
		ft_key_hook_proj(fdf);
	else if (keycode == Z)
		ft_init(fdf);
	ft_expose_hook(fdf);
    */
	return (0);
}

void	ft_key_hook_move(int keycode, t_event val)
{
	if (keycode == RIGHT_ARROW)
	{
		val.x += val.x + (1 * val.size);
	}
	else if (keycode == LEFT_ARROW)
	{
		val.x -= val.x + (1 * val.size);
	}
	else if (keycode == UP_ARROW)
	{
		val.y += val.y - (1 * val.size);
	}
	else if (keycode == DOWN_ARROW)
	{
		val.y += val.y + (1 * val.size);
	}
}
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