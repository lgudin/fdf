/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:18 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/22 14:49:29 by lgudin           ###   ########.fr       */
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
	char		***tabis;

	tabis = NULL;
	if (!(tabis = ft_get_tabis(fd, width)))
		return (ft_error("Parsing error : Fill badly formatted"));
	if (!(tab = tab_malloc(tab, width)))
		return (ft_error("Malloc tab ( read.c ) failed"));
	return (set_tab(tab, width, tabis));
}

int		ft_put_xyz(t_pt **tab, char ***tabis, t_cursor c)
{
	if (check_alti(tabis, c) != 1)
		return ((int)ft_error("alti KO"));
	tab[c.y][c.x].x = c.x;
	tab[c.y][c.x].y = c.y;
	tab[c.y][c.x].z = ft_atoi(tabis[c.y][c.x]);
	tab[c.y][c.x].color = INIT_COLOR;
	free(tabis[c.y][c.x]);
	return (1);
}

t_pt	**set_tab(t_pt **tab, t_cursor *width, char ***tabis)
{
	t_cursor	c;

	c.y = -1;
	while (++c.y < width->y)
	{
		c.x = -1;
		while (++c.x < width->x)
			if (!(ft_put_xyz(tab, tabis, c)))
				return (ft_error("ft_put_xyz abort"));
		free(tabis[c.y][c.x]);
		free(tabis[c.y]);
		tabis[c.y] = NULL;
	}
	free(tabis[c.y]);
	tabis[c.y] = NULL;
	free(tabis);
	tabis = NULL;
	return (tab);
}

int		check_alti(char ***tabis, t_cursor c)
{
	if ((tabis[c.y][c.x][0] == '-' &&
		ft_strlenb(tabis[c.y][c.x]) > 7) ||
			ft_strlenb(tabis[c.y][c.x]) > 6)
	{
		return ((int)ft_error("Too big/small short int"));
	}
	if (((tabis[c.y][c.x][0] == '-' &&
		ft_strlenb(tabis[c.y][c.x]) == 6) ||
			ft_strlenb(tabis[c.y][c.x]) == 5) &&
				(ft_ismax(tabis[c.y][c.x]) == 0))
		return ((int)ft_error("Too big/mall short int"));
	return (1);
}
