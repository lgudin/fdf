/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:46:32 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/17 15:08:31 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define FALSE 0
# define TRUE 1
# define HAUTEUR 750
# define LARGEUR 1250

# define DVD_SPEED 5
# define MOVE_SPEED 1
# define ZOOM_SPEED 1.1
# define ALTI_SPEED 0.1

# define PLAYER_HEIGHT 3
# define INIT_SIZE 1
# define INIT_ALTI 1
# define INIT_COLOR BLUE

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# include "definekey.h"
# include "colors.h"
# include "enum.h"
# include "struct.h"

/*
** READ.C
*/

t_pt	**ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt	**get_points(int fd, t_pt **tab, t_cursor *width);
int		check_alti(char ***tabis, t_cursor c);

/*
** MAIN.C
*/

void	*ft_error(char *s);

/*
** PROJECTION.C
*/

void	projection_tintintin(t_fdf *env);
void	projection_para(t_fdf *env);

/*
** GET_LINES.C
*/

char	*get_big_line(int fd, t_cursor *width);
char	***ft_get_tabis(int fd, t_cursor *width);
char	**ft_get_basic_map(int fd, t_cursor *width);

/*
** TOOL.C
*/

char	*ft_strjoinfree(char const *s1, char const *s2);
int		ft_tablen(char **tab);
int		line_check(char *tab);
void	ft_tabfree(char **str);
int		ft_ismax(char *str);

/*
** BRESENHAM.C
*/

int		draw_line(t_fdf *env, t_proj point_zero, t_proj point_one);
int		another_function(t_fdf *env, t_proj point_zero, t_proj point_one);
int		function(t_fdf *env, t_proj point_zero, t_proj point_one);

/*
** MALLOCATOR.C
*/

t_proj	**proj_tab_malloc(t_proj **tab, t_cursor *width);
t_pt	**tab_malloc(t_pt **tab, t_cursor *width);

/*
** PRINT.C
*/

void	fill_image(t_fdf *env);
void	ft_put_pixel(t_fdf *env, int x, int y, t_rgb color);
void	ft_print_menu(t_fdf *env);

/*
** PRINT_MAIN.c
*/

void	ft_lock_menu(t_fdf *env);
void	ft_putwin(t_fdf *env);
void	ft_regular_menu(t_fdf *env);
void	ft_game_menu(t_fdf *env);

/*
** HOOK.cC
*/

int		ft_key_hook(int keycode, t_fdf *env);
int		ft_expose_hook(t_fdf *env);

/*
** KEYHOOK_SET.C
*/

void	ft_key_hook_proj_mode(t_event *val);
void	ft_key_hook_move(int keycode, t_fdf *env);
void	ft_key_hook_alti(int keycode, t_event *val);
void	ft_key_hook_zoom(int keycode, t_event *val);
void	ft_key_hook_color_mode(t_event *val);

/*
** KEYHOOK_SETB.C
*/

void	ft_key_hook_set_lock(t_fdf *env);
void	ft_key_hook_set_regu_back(t_fdf *env);
void	ft_move_pers(int keycode, t_fdf *env);
void	ft_key_hook_reset(t_fdf *env);

/*
** COLOR_SET.C
*/

t_rgb	hex_to_rgb(int hex_color);
int		set_color(t_pt tab, t_event *val);
void	dvd_color_set(t_fdf *env);

/*
** COLOR_MODES.C
*/

int		color_set_mode_map(float z);
int		color_set_mode_dvd(float z);
int		color_set_mode_vaporwave(float z);
int		color_set_mode_laby(float z, float player_size);

/*
** LOCK_SCREEN.C
*/

int		lock_color_switch(void);
void	ft_get_borne(t_fdf *env);
int		ft_boing(t_fdf *env);
void	ft_ca_bouge(t_fdf *env);

/*
** INIT.C
*/

void	ft_init(t_fdf *env);
void	val_init(t_event *val);
void	ptr_init(t_ptr *ptr);
void	ft_init_game(t_fdf *env);

/*
** PLAYER_MOVE.C
*/

void	ft_move_right(t_fdf *env);
void	ft_move_left(t_fdf *env);
void	ft_move_down(t_fdf *env);
void	ft_move_up(t_fdf *env);
void	ft_player_anim(t_fdf *env);

/*
** PLAYER_CHECK_SET.C
*/

int		ft_is_win(t_fdf *env);
void	ft_put_around(t_fdf *env);
void	ft_del_around(t_fdf *env);
int		ft_check_around(t_fdf *env);
void	ft_putwin(t_fdf *env);

#endif
