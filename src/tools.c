/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:07:49 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/21 19:14:10 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_tabfree(char **str)
{
	int y;

	y = 0;
	while (str[y])
	{
		if (str[y])
			ft_strdel(&str[y]);
		y++;
	}
	ft_strdel(&str[y]);
	if (str)
		free(str);
	str = NULL;
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	str = ft_strcpy(str, s1);
	free((char*)s1);
	return (ft_strcat(str, s2));
}

int		ft_tablen(char **tab)
{
	int y;

	y = -1;
	while (tab[++y])
		y += 1 - 1;
	return (y);
}

int		ft_ismax(char *str)
{
	char	*s;
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	if (ft_strlen(str) == (str[0] == '-' ? 6 : 5))
	{
		if (str[0] == '-')
			s = ft_strdup("-32768");
		else
			s = ft_strdup("32767");
		while (s[++i])
		{
			if (s[i] != str[i] && s[i] < str[i] && ret == 0)
				ret = -1;
			else if (s[i] > str[i] && ret == 0)
				ret = 1;
		}
	}
	ft_strdel(&s);
	if (ret == -1)
		return ((int)ft_error("Too big altitude value"));
	return (1);
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
