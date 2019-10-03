/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/03 21:50:33 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 
# define FALSE 0
# define TRUE 1
# define LAYOUT -1500
# define SIZE 2
# define HAUTEUR 0.2

#include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

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
t_pt	**tab_malloc(t_pt **tab, t_cursor *width);
t_pt **ft_read_points(char *av, t_pt **tab, t_cursor *width);
t_pt **get_points(int fd, t_pt **tab, t_cursor *width);
int		get_nbr(char *line, int *len);
char	*get_big_line(int fd);
int     ft_tablen(char **tab);
/*
** MAIN.C
*/
int		ft_error(void);
void    print_map(t_pt **map, t_ptr ptr, t_cursor *width);
void bresenham(int x1, int y1, int x2, int y2, int *win_ptr, int *mlx_ptr, int color);
/*
** TOOL.C
*/
char		*ft_strjoinfree(char const *s1, char const *s2);
/*
**
*/
int	draw_line(t_pt point_zero, t_pt point_one, t_ptr ptr);
int	another_function(t_pt point_zero, t_pt point_one, t_ptr ptr);
int	function(t_pt point_zero, t_pt point_one, t_ptr ptr);

#endif