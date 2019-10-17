/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:11:54 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 15:09:00 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct	s_event
{
	float					x;
	float					y;
	float					size;
	float					alti;
	float					angle;
	int						init_color;
	float					player_size;
	enum e_proj_mode	p_mod;
	enum e_color_mode		color_mode;
	enum e_stat_game		game;
}				t_event;

typedef struct	s_rgb
{
	unsigned char			color_r;
	unsigned char			color_g;
	unsigned char			color_b;
}				t_rgb;

typedef struct	s_proj
{
	long					x;
	long					y;
	t_rgb					color;
}				t_proj;

typedef struct	s_pt
{
	float					x;
	float					y;
	float					z;
	int						color;
}				t_pt;

typedef struct	s_cursor
{
	int						x;
	int						y;
}				t_cursor;

typedef struct	s_ptr
{
	int						*mlx;
	int						*win;
	int						*img;
	char					*img_data;
	int						bpp;
	int						size_line;
	int						endian;
}				t_ptr;

typedef struct	s_fdf
{
	t_event					*val;
	t_proj					**proj;
	t_cursor				*width;
	t_cursor				layout;
	t_cursor				borne;
	t_cursor				player_c;
	t_cursor				borne_min;
	t_rgb					lock_color;
	t_ptr					ptr;
	t_pt					**tab;
	int						prev_play;
	enum e_stat_mode		stat_mode;
	enum e_dir				dir;
}				t_fdf;

#endif
