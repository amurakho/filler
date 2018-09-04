/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:46:02 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/29 16:46:04 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static void		ft_getmap_xy_struct(t_mlx *visual)
{
	size_t	y;

	y = 0;
	visual->mapxyz = (int **)malloc((visual->linenb) * sizeof(int *));
	while (y < visual->linenb)
	{
		visual->mapxyz[y] = (int *)malloc(ft_strlen(visual->map[0])
			* sizeof(int));
		y++;
	}
}

void			ft_getmap_xy(t_mlx *visual, size_t y, size_t x)
{
	int		i;

	if (visual->firststep == 0)
		ft_getmap_xy_struct(visual);
	while (y < visual->linenb)
	{
		i = 0;
		x = 0;
		while (visual->map[y][i] != '\0')
		{
			if (visual->map[y][i] == '.')
				visual->mapxyz[y][x++] = 0;
			else if (visual->map[y][i] == 'X')
				visual->mapxyz[y][x++] = 1;
			else if (visual->map[y][i] == 'x')
				visual->mapxyz[y][x++] = 10;
			else if (visual->map[y][i] == 'O')
				visual->mapxyz[y][x++] = 2;
			else if (visual->map[y][i] == 'o')
				visual->mapxyz[y][x++] = 20;
			i++;
		}
		y++;
	}
}
