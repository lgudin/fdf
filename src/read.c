/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/14 21:05:04 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pt	**ft_read_points(char *av, t_pt **tab, t_cursor *width)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	tab = get_points(fd, tab, width);
	close(fd);
	return (tab);
}

char	***ft_str_ninja(int fd, t_cursor *width, char ***tabis)
{
	char	**basic_map;
	char	*big_line;
	int		y;

	if (!(big_line = get_big_line(fd)) || ft_strlen(big_line) == 0)
	{
		ft_strdel(&big_line);
		return (ft_error("bigline bug"));
	}
	basic_map = ft_strsplit(big_line, '\n');
	ft_strdel(&big_line);
	width->y = ft_tablen(basic_map);
	if (!(tabis = (char ***)ft_memalloc(sizeof(char **) * (width->y + 1))))
		return (ft_error("Malloc tabis ( read.c ) failed"));
	y = -1;
	while (++y < width->y)
	{
		tabis[y] = ft_strsplit(basic_map[y], ' ');
		ft_strdel(&basic_map[y]);
		printf("width y = %d, y = %d, len y = %d\n", width->y, y,  ft_tablen(tabis[y]));
		if (width->y > 1 && y > 0 && ft_tablen(tabis[y]) != ft_tablen(tabis[y - 1]))
			return (ft_error("tablen"));
	}
	free(basic_map);
	width->x = ft_tablen(tabis[0]);
	return (tabis);
}

t_pt	**get_points(int fd, t_pt **tab, t_cursor *width)
{
	t_cursor	c;
	char		***tabis;

	tabis = NULL;
	if (!(tabis = ft_str_ninja(fd, width, tabis)))
		return (ft_error("Parsing error : Fill badly formatted"));
	if (!(tab = tab_malloc(tab, width)))
		return (ft_error("Malloc tab ( read.c ) failed"));
	c.y = 0;
	while (c.y < width->y)
	{
		c.x = 0;
		while (c.x < width->x)
		{
			if (((tabis[c.y][c.x][0] == '-' && ft_strlen(tabis[c.y][c.x]) >= 11) || ft_strlen(tabis[c.y][c.x]) >= 10) && (ft_ismax(tabis[c.y][c.x]) == 0))
				return (ft_error(tabis[c.y][c.x][0] == '-' ?
					"Alt trop basse" : "Alt trop elevée"));
			tab[c.y][c.x].x = c.x;
			tab[c.y][c.x].y = c.y;
			tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]);
			tab[c.y][c.x].color = INIT_COLOR;
			c.x++;
		}
		ft_strdel(tabis[c.y]);
		c.y++;
	}
	free(tabis);
	return (tab);
}

int		ft_ismax(char *str)
{
	char *s;
	int i;

	i = 0;
	if (ft_strlen(str) == (str[0] == '-' ? 11 : 10))
	{
		if (str[0] == '-')
			s = ft_strdup("-2147483648");
		else
			s = ft_strdup("2147483647");
			printf("%s",s);
		while(s[i])
		{
			if (s[i] != str[i] && s[i] < str[i])
			{
					ft_putchar('U');
					return((int)ft_error("Too big altitude value"));
			}
			else if (s[i] != str[i])
				return (1);
			i++;
		}
	}
	else
		return((int)ft_error("Too big altitude value"));
	return (1);
}
