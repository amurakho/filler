/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:41:11 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:41:13 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

int		ft_findnumber(t_filler *filler, int counter)
{
	int number;
	int e_x;
	int e_y;

	e_x = filler->figure_dot[counter].x;
	e_y = filler->figure_dot[counter].y;
	number = filler->map_y;
	number = (e_x * number) + e_y;
	return (number);
}

size_t	ft_findmaxdist(t_filler *filler, int counter, size_t old_dist)
{
	int		number;
	size_t	new_dist;

	number = ft_findnumber(filler, counter);
	new_dist = filler->points[number].distance;
	if (new_dist < old_dist)
		return (new_dist);
	else
		return (old_dist);
}

int		ft_testingpoint(int c, t_filler *filler)
{
	int number;
	int t_x;
	int t_y;

	t_x = filler->figure_dot[c].x;
	t_y = filler->figure_dot[c].y;
	number = (t_x * filler->map_y) + t_y;
	if (t_x >= 0 && t_y >= 0 && t_x + 1 <= filler->map_x
		&& t_y + 1 <= filler->map_y)
	{
		if (filler->figure_dot[c].symbol == '.')
			return (1);
		if (filler->points[number].symbol == '.')
			return (1);
		if (filler->points[number].symbol == filler->my)
		{
			if (filler->if_stand != 1 && filler->figure_dot[c].symbol == '*')
			{
				filler->if_stand = 1;
				return (1);
			}
		}
	}
	return (0);
}

size_t	ft_iftest(t_filler *filler, size_t distance)
{
	int counter;

	counter = 0;
	while (filler->figure_dot[counter].symbol)
	{
		if (!ft_testingpoint(counter, filler))
			return (0);
		if (filler->figure_dot[counter].symbol == '*')
			distance = ft_findmaxdist(filler, counter, distance);
		counter++;
	}
	if (!filler->if_stand)
		return (0);
	return (distance);
}
