/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 19:38:53 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 

# define FALSE 0
# define TRUE 1

# define MOVE_SPEED 0.1
# define ZOOM_SPEED 0.1



#include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../42_Projects/libft/libft.h"
# include "definekey.h"
# include "colors.h"

enum color_mode
{
    REGULAR, // REGULAR vaut 0 ;) 
    MAP,
    EGYPTIAN,
    VAPORWAVE,
}       color_mode;

typedef struct s_event
{
    float x;
    float y;
    float size;
    float alti;
    enum color_mode color;
}               t_event;

typedef struct s_proj
{
    float x;
    float y;
    int color;
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

}               t_ptr;

/*
** READ.C
*/

t_pt     **ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt     **get_points(int fd, t_pt **tab, t_cursor *width);

/*
** MAIN.C
*/

int		 ft_error(void);
void     projection_tintintin(t_proj **proj, t_pt **tab, t_cursor *width, t_event val);

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
void    set_full_map(t_ptr ptr, t_cursor *width, int color);

/*
** HOOK.cC
*/

int     ft_key_hook(int keycode, t_event *val);
void	ft_key_hook_move(int keycode, t_event *val);
void	ft_key_hook_zoom(int keycode, t_event *val);
void	ft_key_hook_reset(t_event val);
//int	ft_expose_hook(t_ptr ptr);

/*
** COLOR_SET.C
*/
int     set_color(t_pt tab, t_event *val);
int     color_set_map(t_pt tab);
int     color_set_vaporwave(t_pt tab);
#endif