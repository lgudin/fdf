/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:23:38 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/18 09:05:56 by lgudin           ###   ########.fr       */
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
};

enum	e_stat_game
{
	LOOSE,
	WIN,
};

enum	e_stat_mode
{
	REG_S,
	LOCK_S,
};

enum	e_proj_mode
{
	PARA,
	CONIQUE,
	LAST_P,
};

enum	e_color_mode
{
	REGULAR,
	MAP,
	EGYPTIAN,
	VAPORWAVE,
	LAST,
	DVD,
	LABY,
};

#endif
