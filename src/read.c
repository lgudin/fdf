/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/06 16:51:58 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pt **ft_read_points(char *av, t_pt **tab, t_cursor *width)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (FALSE);
   	tab = get_points(fd, tab, width);
	close(fd);
	return (tab);
}
char ***ft_fruit_ninja(int fd, t_cursor *width, char ***tabis)
{
	char 	**basic_map;
	char	 *big_line;
	int y;
	
	y = 0;

	big_line = get_big_line(fd);
	basic_map = ft_strsplit(big_line, '\n'); // penser aux leaks
	ft_strdel(&big_line);
	width->y = 	ft_tablen(basic_map);
	
	if (!(tabis = (char ***)malloc(sizeof(char **) * (width->y + 1))))
		return (0);
	y = -1;
	while (++y < width->y)
	{
		tabis[y] = ft_strsplit(basic_map[y], ' ');
		ft_strdel(&basic_map[y]);
	}
	free(basic_map);
	width->x = ft_tablen(tabis[0]);
	return (tabis);
}

t_pt 	**get_points(int fd, t_pt **tab, t_cursor *width)
{
	t_cursor c;
	char 	***tabis;

	tabis = NULL;
	tabis = ft_fruit_ninja(fd, width, tabis);
	if (!(tab = tab_malloc(tab, width)))
		return (NULL);
	c.y = 0;
	while (c.y < width->y)
	{
		c.x = 0;
		while (c.x < width->x)
		{
			tab[c.y][c.x].x =  c.x;
			tab[c.y][c.x].y =   c.y;
			tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]);
			tab[c.y][c.x].color = BASIC_COLOR;
			//printf("x = %.0f y = %.0f z = %.0f color = %d\n", tab[c.y][c.x].x, tab[c.y][c.x].y , tab[c.y][c.x].z, tab[c.y][c.x].color);
			c.x++;
		}
		ft_strdel(tabis[c.y]);
		c.y++;
	}
	free(tabis);
	return (tab);
}