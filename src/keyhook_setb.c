/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_setb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:12:21 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 12:13:01 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_pers(int keycode, t_fdf *env)
{
	if (keycode == UP_ARROW)
		ft_move_up(env);
	else if (keycode == LEFT_ARROW)
		ft_move_left(env);
	else if (keycode == DOWN_ARROW)
		ft_move_down(env);
	else if (keycode == RIGHT_ARROW)
		ft_move_right(env);
	if (ft_is_win(env) == 1)
	{
		ft_del_around(env);
		env->val->game = WIN;
	}
}
