/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:12 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/02 13:25:34 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H 
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_pt
{
    int x;
    int y;
    int z;
    int color;
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
#endif