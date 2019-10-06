/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 21:07:36 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 

# define FALSE 0
# define TRUE 1

# define HAUTEUR 1280
# define LARGEUR 1920 

# define MOVE_SPEED 1
# define ZOOM_SPEED 1
# define ALTI_SPEED 1

#define INIT_SIZE 3
#define INIT_ALTI 0.3

# define BASIC_COLOR BLUE



#include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "definekey.h"
# include "colors.h"

enum color_mode
{
    REGULAR, // REGULAR vaut 0 ;) 
    MAP,
    EGYPTIAN,
    VAPORWAVE,
    LAST,
}       color_mode;

typedef struct s_event
{
    float x;
    float y;
    float size;
    float alti;
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

}               t_ptr;

typedef struct  s_fdf
{
    t_event     *val;
    t_proj      **proj;
    t_cursor    *width;
    t_ptr       ptr;
    t_pt        **tab;
}               t_fdf;


/*
** READ.C
*/

t_pt **ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt     **get_points(int fd, t_pt **tab, t_cursor *width);

/*
** MAIN.C
*/

int		ft_error(char *s);
void projection_tintintin(t_fdf *env);
/*
** TOOL.C
*/

char    *ft_strjoinfree(char const *s1, char const *s2);
char    *get_big_line(int fd);
int     ft_tablen(char **tab);

/*
** BRESENHAM.C
*/

int     draw_line(t_proj point_zero, t_proj point_one, t_ptr ptr);
int     another_function(t_proj point_zero, t_proj point_one, t_ptr ptr);
int     function(t_proj point_zero, t_proj point_one, t_ptr ptr);

/*
** MALLOCATOR.C
*/

t_proj	**proj_tab_malloc(t_proj **tab, t_cursor *width);
t_pt	**tab_malloc(t_pt **tab, t_cursor *width);

/*
** PRINT.C
*/

void    print_map(t_proj **map, t_ptr ptr, t_cursor *width);
void    set_full_map(t_ptr ptr, int color);

/*
** HOOK.cC
*/

int     ft_key_hook(int keycode, t_fdf *env);
void	ft_key_hook_move(int keycode, t_event *val);
void	ft_key_hook_alti(int keycode, t_event *val);
void	ft_key_hook_zoom(int keycode, t_event *val);
void	ft_key_hook_color_mode(t_event *val);
void	val_init(t_event *val, t_cursor *width);
//int	ft_expose_hook(t_ptr ptr);

/*
** COLOR_SET.C
*/
t_rgb    hex_to_rgb(int hex_color, t_rgb splitted_color);
int     set_color(t_pt tab, t_event *val);
int     color_set_map(float z);
int     color_set_vaporwave(float z);
#endif