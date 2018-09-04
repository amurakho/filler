/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:41:28 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:41:38 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

void	ft_smallbad(int c, char *line, t_filler *flr, int l_c)
{
	if ((c % 7 == 0 && line[l_c] == flr->enemy && c <= 65))
	{
		flr->enemy_x = 14;
		flr->enemy_y = 0;
	}
	else if (c % 4 == 0 && c <= 25 && line[l_c] != '.')
		flr->bad_syt = 0;
	else
	{
		flr->enemy_x = 0;
		flr->enemy_y = 0;
	}
}

void	ft_whereenemy(t_filler *flr, int c, int l_c, char *line)
{
	if (flr->bad_syt && flr->map_x * flr->map_y == 255)
		ft_smallbad(c, line, flr, l_c);
	if (flr->points[c].symbol != flr->enemy && line[l_c]
		== flr->enemy && !flr->bad_syt)
		ft_editenemy(flr, c);
}

void	ft_makepoints(t_filler *flr, char *line)
{
	int x_c;
	int c;
	int l_c;

	x_c = 0;
	l_c = 0;
	c = 0;
	while (c != flr->map_y * flr->map_x)
	{
		if (!line[l_c])
			get_line(&line, &x_c, &l_c, 1);
		else
		{
			if (line[l_c] == flr->enemy && !flr->enemy_x && !flr->enemy_y)
				ft_makeendcoord(flr, x_c, l_c);
			flr->points[c].x = x_c;
			flr->points[c].y = l_c;
			ft_whereenemy(flr, c, l_c, line);
			flr->points[c].symbol = line[l_c];
			c++;
			l_c++;
		}
	}
	flr->points[c].symbol = '\0';
}

void	ft_parsemap(t_filler *filler, char *pl_line)
{
	if (!filler->box_init)
	{
		ft_size(&*filler, pl_line, 1);
		filler->points = (t_point*)malloc(sizeof(t_point)
			* ((filler->map_y * filler->map_x) + 1));
		filler->box_init = 1;
		if (filler->map_x * filler->map_y == 255 && filler->my == 'X')
			filler->bad_syt = 1;
	}
	get_next_line(0, &pl_line);
	get_next_line(0, &pl_line);
	pl_line += 4;
	ft_makepoints(filler, pl_line);
	ft_makedistance(filler);
	ft_findstart(filler);
}
