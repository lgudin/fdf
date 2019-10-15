/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/15 18:12:48 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pt	**ft_read_points(char *av, t_pt **tab, t_cursor *width)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (ft_error("Bad File Descriptor"));
	tab = get_points(fd, tab, width);
	close(fd);
	return (tab);
}

t_pt	**get_points(int fd, t_pt **tab, t_cursor *width)
{
	t_cursor	c;
	char		***tabis;

	tabis = NULL;
	if (!(tabis = ft_get_tabis(fd, width)))
		return (ft_error("Parsing error : Fill badly formatted"));
	if (!(tab = tab_malloc(tab, width)))
		return (ft_error("Malloc tab ( read.c ) failed"));
	c.y = -1;
	while (++c.y < width->y)
	{
		c.x = -1;
		while (++c.x < width->x)
		{
			if (check_alti(tabis, c) != 1)
				return (ft_error("alti KO"));
			tab[c.y][c.x].x = c.x;
			tab[c.y][c.x].y = c.y;
			tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]);
			tab[c.y][c.x].color = INIT_COLOR;
		}
		ft_strdel(tabis[c.y]);
	}
	free(tabis);
	return (tab);
}

int		check_alti(char ***tabis, t_cursor c)
{
	if (((tabis[c.y][c.x][0] == '-' &&
	ft_strlen(tabis[c.y][c.x]) >= 11) ||
	ft_strlen(tabis[c.y][c.x]) >= 10) &&
	(ft_ismax(tabis[c.y][c.x]) == 0))
		return ((int)ft_error("Too big/mall int"));
	return (1);
}
