/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:51:27 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/16 20:58:57 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_get_basic_map(int fd, t_cursor *width)
{
	char	*big_line;
	char	**basic_map;

	if (!(big_line = get_big_line(fd, width)) || ft_strlen(big_line) == 0)
	{
		ft_strdel(&big_line);
		return (ft_error("bigline bug"));
	}
	basic_map = ft_strsplit(big_line, '\n');
	ft_strdel(&big_line);
	if (width->y == ft_tablen(basic_map))
		return (basic_map);
	ft_tabfree(basic_map);
	return (ft_error("probleme formatage nb lignes"));
}

char	***ft_get_tabis(int fd, t_cursor *width)
{
    char    ***tabis;
	char	**basic_map;
	int		y;

	if (!(basic_map = ft_get_basic_map(fd, width)))
		return (ft_error("ft_get_basic_map return FALSE"));
	if (!(tabis = (char ***)ft_memalloc(sizeof(char **) * (width->y + 1))))
		return (ft_error("Malloc tabis ( read.c ) failed"));
	y = -1;
	while (++y < width->y)
	{
		tabis[y] = ft_strsplit(basic_map[y], ' ');
		if (width->y > 1 && y > 0
			&& ft_tablen(tabis[y]) != ft_tablen(tabis[y - 1]))
		{
			ft_tabfree(basic_map);
			return (ft_error("tablen"));
		}
	}
	ft_tabfree(basic_map);
	width->x = ft_tablen(tabis[0]);
	return (tabis);
}

char	*get_big_line(int fd, t_cursor *width)
{
	char	*line;
	char	*big_line;
	int		i;
	int		gnl;

	i = 0;
	big_line = ft_strnew(2);
	while (big_line[i++])
	{
		big_line[i] = 0;
	}
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		big_line = ft_strjoinfree(big_line, line);
		if (!(line_check(line)))
			return (ft_error("Invalid char in file"));
		big_line = ft_strcat(big_line, "\n");
		free(line);
		width->y++;
	}
	if (gnl == -1)
		return (ft_error("GNL ret -1"));
	return (big_line);
}

