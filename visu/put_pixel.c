/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:46:10 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/29 16:46:12 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static int		ft_get_color(t_mlx *v, int y, int x)
{
	if (v->mapxyz[y][x] == 1)
		return (0xFF0000);
	else if (v->mapxyz[y][x] == 10)
		return (0x550000);
	else if (v->mapxyz[y][x] == 2)
		return (0x0000FF);
	else if (v->mapxyz[y][x] == 20)
		return (0x000055);
	else
		return (0xFFFFFF);
}

int				ft_put_pixel_first_round(t_mlx *v, size_t y, size_t x)
{
	size_t	tmpx;
	size_t	tmpy;

	if ((v->mapxyz[y][x] >= v->mapxyz[y][x + 1] ||
		v->mapxyz[y][x] < v->mapxyz[y][x + 1]) && x < ft_strlen(v->map[y]) - 1)
	{
		tmpx = (x * 10);
		while (tmpx < ((x + 1) * 10))
			mlx_pixel_put(v->mlx, v->win, 100 + tmpx++, 190 + (y * 10),
			ft_get_color(v, y, x));
	}
	if (y < v->linenb - 1 && (v->mapxyz[y][x] >= v->mapxyz[y + 1][x] ||
		v->mapxyz[y][x] < v->mapxyz[y + 1][x]) && x < ft_strlen(v->map[y + 1]))
	{
		tmpy = (y * 10);
		while (tmpy < ((y + 1) * 10))
			mlx_pixel_put(v->mlx, v->win, 100 + (x * 10), 190 + tmpy++,
			ft_get_color(v, y, x));
	}
	return (++x);
}

int				ft_put_pixel_other_round(t_mlx *v, size_t y, size_t x)
{
	size_t	tmpx;
	size_t	tmpy;

	if (x + 1 < ft_strlen(v->map[y]) && v->mapxyz[y][x] != 0 &&
	v->mapxyz[y][x + 1] != 0)
		if ((v->mapxyz[y][x] >= v->mapxyz[y][x + 1] ||
			v->mapxyz[y][x] < v->mapxyz[y][x + 1]) &&
			x < ft_strlen(v->map[y]) - 1)
		{
			tmpx = (x * 10);
			while (tmpx < ((x + 1) * 10))
				mlx_pixel_put(v->mlx, v->win, 100 + tmpx++, 190 + (y * 10),
				ft_get_color(v, y, x));
		}
	if (y + 1 < v->linenb && v->mapxyz[y][x] != 0 && v->mapxyz[y + 1][x] != 0)
		if (y < v->linenb - 1 && (v->mapxyz[y][x] >= v->mapxyz[y + 1][x] ||
			v->mapxyz[y][x] < v->mapxyz[y + 1][x]) &&
			x < ft_strlen(v->map[y + 1]))
		{
			tmpy = (y * 10);
			while (tmpy < ((y + 1) * 10))
				mlx_pixel_put(v->mlx, v->win, 100 + (x * 10), 190 + tmpy++,
				ft_get_color(v, y, x));
		}
	return (++x);
}

void			ft_put_pixel(t_mlx *v)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < v->linenb)
	{
		x = 0;
		while (x < ft_strlen(v->map[0]))
		{
			if (v->firststep == 0)
				x = ft_put_pixel_first_round(v, y, x);
			else
				x = ft_put_pixel_other_round(v, y, x);
		}
		y++;
	}
}
