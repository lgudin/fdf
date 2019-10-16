/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:13:06 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 22:15:54 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	color_set_mode_vaporwave(float z)
{
	if (z < 1)
		return (VAPOR_BLUE);
	else
		return (VAPOR_PINK);
}

int	color_set_mode_map(float z)
{
	if (z <= -5)
		return (DEEP_BLUE);
	else if (z <= 0)
		return (BLUE);
	else if (z <= 10)
		return (GRASSE);
	else if (z <= 25)
		return (BROWN);
	else
		return (WHITE);
}

int	color_set_mode_dvd(float z)
{
	if (z == 0)
		return (BLACK);
	else
		return (-1);
	return ((int)ft_error("DVD Color failed"));
}

int	color_set_mode_laby(float z, float player_size)
{
	if (z == 0)
		return (PURPLE);
	else if (z == player_size)
		return (VAPOR_PINK);
	else
		return (LIGHT_BLUE);
}
