/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/10 10:50:19 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 

# define FALSE 0
# define TRUE 1

# define HAUTEUR 800
# define LARGEUR 1250

# define DVD_SPEED 5
# define MOVE_SPEED 1
# define ZOOM_SPEED 1.1
# define ALTI_SPEED 0.1

#define INIT_SIZE 1
#define INIT_ALTI 0.3
# define INIT_COLOR BLUE



#include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

//# include "../../libft/libft.h" // PC 42
#include  "../../42_Projects/libft/libft.h" // PC Portable

# include "definekey.h"
# include "colors.h"
# include "struct.h"

/*
** READ.C
*/
char    ***ft_str_ninja(int fd, t_cursor *width, char ***tabis);
t_pt    **ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt    **get_points(int fd, t_pt **tab, t_cursor *width);
/*
** MAIN.C
*/
int		ft_error(char *s);
/*
** PROJECTION.C
*/
void    projection_tintintin(t_fdf *env);
void    projection_para(t_fdf *env);
/*
** TOOL.C
*/
char    *ft_strjoinfree(char const *s1, char const *s2);
char    *get_big_line(int fd);
int     ft_tablen(char **tab);
/*
** BRESENHAM.C
*/
int     draw_line(t_fdf *env, t_proj point_zero, t_proj point_one);
int     another_function(t_fdf *env, t_proj point_zero, t_proj point_one);
int     function(t_fdf *env, t_proj point_zero, t_proj point_one);
/*
** MALLOCATOR.C
*/
t_proj	**proj_tab_malloc(t_proj **tab, t_cursor *width);
t_pt	**tab_malloc(t_pt **tab, t_cursor *width);
/*
** PRINT.C
*/
void    fill_image(t_fdf *env);
void	ft_put_pixel(t_fdf *env, int x, int y,t_rgb color);
void    set_square(t_cursor p_one, t_cursor p_two,t_fdf *env, int color);
/*
** HOOK.cC
*/
int     ft_key_hook(int keycode, t_fdf *env);
void    ft_key_hook_set_lock(t_fdf *env);
void 	ft_key_hook_set_regu_back(t_fdf *env);
int     ft_expose_hook(t_fdf *env);
/*
** KEYHOOK_SET.C
*/
void    ft_key_hook_proj_mode(t_event *val);
void	ft_key_hook_move(int keycode, t_fdf *env);
void	ft_key_hook_alti(int keycode, t_event *val);
void	ft_key_hook_zoom(int keycode, t_event *val);
void	ft_key_hook_color_mode(t_event *val);
/*
** COLOR_SET.C
*/
t_rgb       hex_to_rgb(int hex_color);
int         set_color(t_pt tab, t_event *val);
void	    dvd_color_set(t_fdf *env);
/*
** COLOR_MODES.C
*/
int         color_set_mode_map(float z);
int         color_set_mode_dvd(float z);
int         color_set_mode_vaporwave(float z);
/*
** LOCK_SCREEN.C
*/

int         lock_color_switch(void);
void        ft_get_borne(t_fdf *env);
int         ft_boing(t_fdf *env);
void        ft_ca_bouge(t_fdf *env);
/*
** INIT.C
*/
void    ft_init(t_fdf *env);
void	val_init(t_event *val);
void	ptr_init(t_ptr *ptr);

#endif
