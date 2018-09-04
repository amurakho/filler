/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:46:17 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/29 16:46:18 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static void		ft_takeres(t_mlx *v, char *line, int cas)
{
	if (cas == 1)
	{
		v->resfirst = ft_atoi(&line[10]);
		v->sres_y = ft_strjoin(v->sres_y, "The result of the first player: ");
		v->sres_y = ft_strjoin(v->sres_y, ft_itoa(v->resfirst));
		mlx_string_put(v->mlx, v->win, 100, 50, 0xFFFFFF, v->sres_y);
	}
	if (cas == 2)
	{
		v->ressec = ft_atoi(&line[10]);
		v->sres_x = ft_strjoin(v->sres_x, "The result of the second player: ");
		v->sres_x = ft_strjoin(v->sres_x, ft_itoa(v->ressec));
		mlx_string_put(v->mlx, v->win, 100, 70, 0xFFFFFF, v->sres_x);
		if (v->resfirst > v->ressec)
			mlx_string_put(v->mlx, v->win, 100, 110, 0x0000FF,
				"The first player wins!");
		else if (v->resfirst < v->ressec)
			mlx_string_put(v->mlx, v->win, 100, 110, 0xFF0000,
				"The second player wins");
		else
			mlx_string_put(v->mlx, v->win, 100, 110, 0xFFFFFF, "Draw!");
	}
	mlx_string_put(v->mlx, v->win, 100, 150, 0xFF0000, "Press ESC to end");
}

static void		ft_parsevmap(t_mlx *v, char *line)
{
	if (v->takemap == 1)
	{
		v->mapjoin = ft_strjoin(v->mapjoin, &line[4]);
		v->mapjoin = ft_strjoin(v->mapjoin, "\n");
		v->linenb++;
	}
	if (v->takemap == 2)
	{
		v->map = ft_strsplit(v->mapjoin, '\n');
		ft_getmap_xy(v, 0, 0);
		ft_put_pixel(v);
		mlx_do_sync(v->mlx);
		v->firststep = 1;
		v->takemap = 0;
	}
}

static void		ft_firstline(t_mlx *v)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(ft_strsub(line, 0, 3), "000") == 0)
		{
			v->takemap = 1;
			v->linenb = 0;
			ft_strclr(v->mapjoin);
		}
		if (ft_strcmp(ft_strsub(line, 0, 5), "Piece") == 0)
			v->takemap = 2;
		ft_parsevmap(v, line);
		if (ft_strcmp(ft_strsub(line, 0, 8), "== O fin") == 0)
			ft_takeres(v, line, 1);
		if (ft_strcmp(ft_strsub(line, 0, 8), "== X fin") == 0)
			ft_takeres(v, line, 2);
	}
}

static int		ft_key_hook(int keycode, t_mlx *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(EXIT_FAILURE);
	}
	v->start = 1;
	mlx_clear_window(v->mlx, v->win);
	ft_firstline(v);
	return (0);
}

int				main(void)
{
	t_mlx v;

	v.start = 0;
	v.takemap = 0;
	v.linenb = 0;
	v.firststep = 0;
	v.sres_y = "\0";
	v.sres_x = "\0";
	v.mapjoin = "\0";
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "Filler V");
	mlx_string_put(v.mlx, v.win, 500,
		500, 0x0000FF, "Press any key, besides ESC");
	mlx_string_put(v.mlx, v.win, 500,
		520, 0xFF0000, "If want to leave press ESC");
	mlx_hook(v.win, 2, 2, ft_key_hook, &v);
	mlx_loop(v.mlx);
}
