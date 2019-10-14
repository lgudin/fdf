/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:07:49 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/14 16:53:17 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	str = ft_strcpy(str, s1);
	free((char*)s1);
	return (ft_strcat(str, s2));
}

char	*get_big_line(int fd)
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
	}
	if (gnl == -1)
		return (ft_error("GNL ret -1"));
	return (big_line);
}

int		ft_tablen(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}

int		line_check(char *tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i] != '-' && tab[i] != ' ' &&
				(tab[i] < '0' || tab[i] > '9'))
			return (0);
	}
	return (1);
}
