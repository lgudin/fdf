/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/02 21:01:40 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_read_points(char *av, t_pt **tab)
{
	int fd;
	int width;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (FALSE);
    width = get_points(fd, tab);
	close(fd);
	return (width);
}

t_pt	**tab_malloc(t_pt **tab, int map_width)
{
	int		y;
	int		x;

	if (!map_width)
		return (NULL);

	if (!(tab = (t_pt **)malloc(sizeof(t_pt *) * (map_width + 1))))
		return (NULL);

	y = -1;
	while (++y < map_width)
	{
		if (!(tab[y] = (t_pt *)malloc(sizeof(t_pt) * (map_width + 1))))
			return (NULL);
		tab[y][map_width].ok = 0;
	}
	tab[map_width] = 0;
	ft_putstrln("MALLOC DONE");
	return (tab);
}

char	*get_big_line(int fd)
{
	char *line;
	char *big_line;

	while (get_next_line(fd, &line))
    {
		big_line = ft_strjoin(big_line, line);
		free(line);
	}
	return (big_line);
}

int		get_points(int fd, t_pt **tab)
{
	t_cursor c;
	char **tabis;
	char **basic_map;
    char *line;
	int len;
	
	len = 0;
	c.x = 0;
	c.y = 0;

	int y;
	int x;
	basic_map = ft_strsplit(get_big_line(fd), '\n');
	while (basic_map[y])
	{
		tabis = ft_strsplit(basic_map[y], ' ');
		y++;
	}
	c.x = 0;
	while (tabis[c.x])
	{
		tab[c.y][c.x].x = c.x;
		tab[c.y][c.x].y = c.y;
		tab[c.y][c.x].z = ft_atoi(tabis[c.x]);
		tab[c.y][c.x].ok = 1;
		printf("point[%d, %d] : \n x %d: y : %d z : %d \n", c.y, c.x,tab[c.y][c.x].x , tab[c.y][c.x].y, tab[c.y][c.x].z);
		c.x++;
	}
	c.y++;
	ft_bzero(tabis, len);
	free(line);
	return (len);
}
/*
nbr = get_nbr(line, &i);
			
			if (c.y == 0)
			{
				tab = malloc_tab(tab, len);
			}
			tab[c.y][c.x].z = nbr;
			tab[c.y][c.x].y = c.y;
			tab[c.y][c.x].x = c.x;
			if (line[i] == ' ')
			{
				i++;
				c.x++;
			}
			*/