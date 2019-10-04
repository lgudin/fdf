/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 17:17:37 by lgudin           ###   ########.fr       */
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
t_pt 	**get_points(int fd, t_pt **tab, t_cursor *width)
{
	t_cursor c;
	char 	***tabis;
	char 	**basic_map;
	char	 *big_line;
	int y;
	
	c.x = 0;
	y = 0;

	big_line = get_big_line(fd);
	basic_map = ft_strsplit(big_line, '\n'); // penser au strsplitfree
	width->y = 	ft_tablen(basic_map);
	
	if (!(tabis = (char ***)malloc(sizeof(char **) * (width->y + 1))))
		return (0);

	c.y = -1;
	while (++c.y < width->y)
	{
		tabis[c.y] = ft_strsplit(basic_map[c.y], ' ');
	}
	width->x = ft_tablen(tabis[0]);
	if (!(tab = tab_malloc(tab, width)))
		return (NULL);
	
	c.y = 0;
	while (c.y < width->y)
	{
		c.x = 0;
		while (c.x < width->x)
		{
			tab[c.y][c.x].x =  c.x * SIZE;
			tab[c.y][c.x].y =   c.y * SIZE;
			tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]) * HAUTEUR;
			//tab[c.y][c.x].color = tab[c.y][c.x].z < 5 ? 0x5555FF : 0xFF5555 ;
			tab[c.y][c.x].color = tab[c.y][c.x].z < -5 ? DEEP_BLUE : tab[c.y][c.x].z < 0 ? BLUE : tab[c.y][c.x].z > 10 ? WHITE : tab[c.y][c.x].z > 5 ? BROWN : GRASSE ;
			c.x++;
		}
		c.y++;
	}
	//penser a free basic map 
	return (tab);
}