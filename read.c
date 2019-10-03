/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/03 14:16:02 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_pt	**tab_malloc(t_pt **tab, t_cursor *width)
{
	int		y;

	if (!width->y)
		return (NULL);

	if (!(tab = (t_pt **)malloc(sizeof(t_pt *) * (width->y + 1))))
		return (NULL);

	y = -1;
	while (++y < width->y)
	{
		if (!(tab[y] = (t_pt *)malloc(sizeof(t_pt) * (width->x + 1))))
			return (NULL);
	}
	tab[width->y] = 0;
	ft_putstrln("MALLOC TAB STRUCT DONE");
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
	tab = tab_malloc(tab, width);
	
	c.y = 0;
	while (c.y < width->y)
	{
		c.x = 0;
		while (c.x < width->x)
		{
			tab[c.y][c.x].x = c.x;
			tab[c.y][c.x].y = c.y;
			tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]);
			//printf("tring to print\n");
			//printf("point[%d, %d] : x %d: y : %d z : %d \n", c.y, c.x,tab[c.y][c.x].x , tab[c.y][c.x].y, tab[c.y][c.x].z);
			c.x++;
		}
		c.y++;
	}
	ft_putstrln("Tab Assigned, get point out ");
	//penser a free basic map 
	return (tab);
}

char	*get_big_line(int fd)
{
	char *line;
	char *big_line;
	int i = 0;

	big_line = ft_strnew(2);
	while (big_line[i++])
	{
		big_line[i] = 0;
	}
	
	line = NULL;
	while (get_next_line(fd, &line))
    {	
		big_line = ft_strjoinfree(big_line, line);
		big_line = ft_strcat(big_line, "\n");
		free(line);
	}

	ft_putstrln("Big line :"); // PRINT
	ft_putstrln(big_line);
	ft_putstrln("Big line return ");
	
	return (big_line);
}

int ft_tablen(char **tab)
{
	int y;
	y = 0;
	while (tab[y])
		y++;
	return (y);
}
