/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:17:45 by lgudin            #+#    #+#             */
/*   Updated: 2019/10/11 14:45:24 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_proj	**proj_tab_malloc(t_proj **tab, t_cursor *width)
{
	int	y;

	if (!width->y)
		return (NULL);
	if (!(tab = (t_proj **)ft_memalloc(sizeof(t_proj *) * (width->y + 1))))
		return (NULL);
	y = -1;
	while (++y < width->y)
		if (!(tab[y] = (t_proj *)ft_memalloc(sizeof(t_proj) * (width->x + 1))))
			return (NULL);
	tab[width->y] = 0;
	return (tab);
}

t_pt	**tab_malloc(t_pt **tab, t_cursor *width)
{
	int	y;

	if (!width->y)
		return (NULL);
	if (!(tab = (t_pt **)ft_memalloc(sizeof(t_pt *) * (width->y + 1))))
		return (NULL);
	y = -1;
	while (++y < width->y)
	{
		if (!(tab[y] = (t_pt *)ft_memalloc(sizeof(t_pt) * (width->x + 1))))
			return (NULL);
	}
	tab[width->y] = 0;
	return (tab);
}
