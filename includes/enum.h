/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:23:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 12:27:58 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H

# define ENUM_H

enum	e_dir
{
	BAS_GAUCHE,
	BAS_DROIT,
	HAUT_GAUCHE,
	HAUT_DROIT,
}	dir;

enum	e_stat_game
{
	LOOSE,
	WIN,
}	stat_game;

enum	e_stat_mode
{
	REG_S,
	LOCK_S,
}	stat_mode;

enum	e_projection_mode
{
	PARA,
	CONIQUE,
	LAST_P,
}	proj_mode;

enum	e_color_mode
{
	REGULAR,
	MAP,
	EGYPTIAN,
	VAPORWAVE,
	LAST,
	DVD,
	LABY,
}	color_mode;

#endif !ENUM_H
