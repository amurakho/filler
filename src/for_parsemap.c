/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 15:01:55 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 15:01:58 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

void	ft_makedistance(t_filler *filler)
{
	int		p_counter;
	size_t	test1;
	size_t	test2;

	p_counter = 0;
	while (filler->points[p_counter].symbol)
	{
		test1 = ft_abs(filler->enemy_x - filler->points[p_counter].x);
		test2 = ft_abs(filler->enemy_y - filler->points[p_counter].y);
		filler->points[p_counter].distance = (test1 + test2);
		p_counter++;
	}
}

void	ft_makestartcoord(t_filler *filler, int x_counter, int y_counter)
{
	filler->start_x = x_counter;
	filler->start_y = y_counter;
}

void	ft_editenemy(t_filler *filler, int counter)
{
	filler->enemy_x = filler->points[counter].x;
	filler->enemy_y = filler->points[counter].y;
}

void	ft_makeendcoord(t_filler *filler, int x_counter, int y_counter)
{
	filler->enemy_x = x_counter;
	filler->enemy_y = y_counter;
}

void	ft_findstart(t_filler *filler)
{
	int		counter;
	size_t	tmp;

	tmp = 9999;
	counter = 0;
	while (filler->points[counter].symbol)
	{
		if (filler->points[counter].distance < tmp &&
			filler->points[counter].symbol == filler->my)
		{
			filler->start_x = filler->points[counter].x;
			filler->start_y = filler->points[counter].y;
			tmp = filler->points[counter].distance;
		}
		counter++;
	}
}
