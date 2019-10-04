/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:07:49 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/04 12:22:45 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		*ft_strjoinfree(char const *s1, char const *s2)
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