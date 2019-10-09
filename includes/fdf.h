/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/09 21:02:16 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 

# define FALSE 0
# define TRUE 1

# define HAUTEUR 1000
# define LARGEUR 1000

#define LAYOUT 300

# define MOVE_SPEED 1
# define ZOOM_SPEED 1.1
# define ALTI_SPEED 0.1

#define INIT_SIZE 1
#define INIT_ALTI 0.1

# define DVD_SPEED 5
# define BASIC_COLOR BLUE


#include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../libft/libft.h" // PC 42
//#include  "../../42_Projects/libft/libft.h" // PC Portable
# include "definekey.h"
# include "colors.h"

enum dir
{
    BAS_GAUCHE,
    BAS_DROIT,
    HAUT_GAUCHE,
    HAUT_DROIT,
}   dir;
enum stat_mode
{
    REG_S,
    LOCK_S,
}    stat_mode;

enum projection_mode
{
    PARA,
    CONIQUE,
    LAST_P,
}    proj_mode;

enum color_mode
{
    REGULAR, // REGULAR vaut 0 ;) 
    MAP,
    EGYPTIAN,
    VAPORWAVE,
    LAST,
    DVD,
}       color_mode;

typedef struct s_event // val 
{
    float x;
    float y;
    float size;
    float alti;
    float wtf;
    float angle;
    enum projection_mode p_mod;
    enum color_mode color_mode;
}               t_event;

typedef struct s_rgb
{
    unsigned char  color_r;
    unsigned char  color_g;
    unsigned char  color_b;
}              t_rgb;

typedef struct s_proj
{
    float x;
    float y;
    t_rgb color;
}               t_proj;

typedef struct  s_pt
{
    float x;
    float y;
    float z;
    int color;
}               t_pt;

typedef struct	s_cursor
{
	int x;
	int y;
}				t_cursor;

typedef struct	s_ptr
{
    int *mlx;
    int *win;
    int *img;
    char *img_data;
    int  bpp; 
    int  size_line;
    int  endian;

}               t_ptr;

typedef struct  s_fdf // env
{
    t_event     *val;
    t_proj      **proj;
    t_cursor    *width;
    t_cursor    layout;
    t_cursor    borne;
    t_cursor    borne_min;
    t_rgb       lock_color;
    t_ptr       ptr;
    t_pt        **tab;
    enum stat_mode stat_mode;
    enum dir    dir;
}               t_fdf;


/*
** READ.C
*/

t_pt    **ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt    **get_points(int fd, t_pt **tab, t_cursor *width);

/*
** MAIN.C
*/

int		ft_error(char *s);
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

int	draw_line(t_fdf *env, t_proj point_zero, t_proj point_one);
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
void	val_init(t_event *val);

int     ft_key_hook(int keycode, t_fdf *env);

void	ft_key_hook_move(int keycode, t_fdf *env);
void	ft_key_hook_alti(int keycode, t_event *val);
void	ft_key_hook_zoom(int keycode, t_event *val);

void    ft_key_hook_screen_mode(t_fdf *env);
void    ft_key_hook_proj_mode(t_event *val);
void	ft_key_hook_color_mode(t_event *val);

void	ft_project_change(int keycode, t_fdf *env);
void	ft_key_hook_rotate(int keycode, t_fdf *env);

int     ft_expose_hook(t_fdf *env);
//int	ft_expose_hook(t_ptr ptr);

/*
** COLOR_SET.C
*/
t_rgb       hex_to_rgb(int hex_color);
int         set_color(t_pt tab, t_event *val);
int         color_set_map(float z);
int         color_set_vaporwave(float z);
/*
** LOCK_SCREEN.C
*/
void        derive_fdf_main(t_fdf *env);
int         derive_fdf(int keycode, t_fdf *env);
int         lock_color_switch(void);
void        ft_get_borne(t_fdf *env);
int         ft_boing(t_fdf *env);
void        ft_ca_bouge(t_fdf *env);

#endif
