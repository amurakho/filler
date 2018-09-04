/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:40:53 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:40:56 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

void	ft_changestart(t_filler *filler)
{
	int number;

	filler->counter++;
	if (filler->counter > filler->map_x * filler->map_y)
		return ;
	number = (filler->start_x * filler->map_y) + filler->start_y;
	filler->points[number].distance = 9999;
	ft_findstart(filler);
	ft_test(filler);
}

void	ft_makere(t_filler *filler)
{
	int counter;
	int r_x;
	int r_y;

	counter = 0;
	r_x = 0 - filler->figure_dot[0].x;
	r_y = 0 - filler->figure_dot[0].y;
	filler->if_stand = 0;
	while (filler->figure_dot[counter].symbol)
	{
		filler->figure_dot[counter].x += r_x;
		filler->figure_dot[counter].y += r_y;
		counter++;
	}
}

void	ft_pfigoord(t_filler *filler, int x, int y)
{
	int counter;

	counter = 1;
	while (filler->figure_dot[counter].symbol)
	{
		filler->figure_dot[counter].x += x;
		filler->figure_dot[counter].y += y;
		counter++;
	}
}

void	ft_findfirstpoint(t_filler *filler, int counter_x)
{
	filler->figure_dot[0].x = filler->start_x - filler->figure_dot[counter_x].x;
	filler->figure_dot[0].y = filler->start_y - filler->figure_dot[counter_x].y;
}

void	ft_test(t_filler *filler)
{
	int		counter;
	size_t	distance;
	size_t	res;

	distance = 9999;
	counter = 0;
	while (filler->figure_dot[counter].symbol)
	{
		ft_findfirstpoint(filler, counter);
		ft_pfigoord(filler, filler->figure_dot[0].x, filler->figure_dot[0].y);
		res = ft_iftest(filler, distance);
		if (res && res < distance)
		{
			distance = res;
			filler->res_x = filler->figure_dot[0].x;
			filler->res_y = filler->figure_dot[0].y;
		}
		counter++;
		ft_makere(filler);
	}
	if (!filler->res_x && !filler->res_y)
		ft_changestart(filler);
}
