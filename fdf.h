/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/02 20:40:32 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 
# define FALSE 0
# define TRUE 1

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct  s_pt
{
    int x;
    int y;
    int z;
    int color;
    int ok;
}       t_pt;

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
int		ft_read_points(char *av, t_pt **tab);
int		get_points(int fd, t_pt **tab);
int		get_nbr(char *line, int *len);
t_pt	**tab_malloc(t_pt **tab, int map_width);
/*
** MAIN.C
*/
void    print_map(t_pt **map, t_ptr ptr, int width);
void bresenham(int x1, int y1, int x2, int y2, int *win_ptr, int *mlx_ptr, int color);

#endif