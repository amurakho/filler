/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:51:19 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:51:22 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

void	ft_makefigure(t_filler *filler, char *line)
{
	int counter;
	int l_counter;
	int x_counter;

	x_counter = 0;
	l_counter = 0;
	counter = 0;
	while (counter != filler->figure_y * filler->figure_x)
	{
		if (!line[l_counter])
		{
			get_line(&line, &x_counter, &l_counter, 0);
			filler->figure[x_counter] = ft_strdup(line);
		}
		else
		{
			filler->figure_dot[counter].x = x_counter;
			filler->figure_dot[counter].y = l_counter;
			filler->figure_dot[counter].symbol = line[l_counter];
			counter++;
			l_counter++;
		}
	}
	filler->figure_dot[counter].symbol = '\0';
}

char	**ft_memcontainer(char **container, int x, int y)
{
	int counter;

	container = (char**)malloc(sizeof(char*) * x);
	counter = 0;
	while (counter != x)
	{
		container[counter] = ft_strnew(y);
		counter++;
	}
	return (container);
}

void	ft_parsefigure(t_filler *filler, char *pl_line)
{
	ft_size(filler, pl_line, 0);
	filler->figure_dot = (t_figure_dot*)malloc(sizeof(t_figure_dot)
		* ((filler->figure_x * filler->figure_y) + 1));
	filler->figure = ft_memcontainer(filler->figure,
		filler->figure_x, filler->figure_y);
	get_next_line(0, &pl_line);
	filler->figure[0] = ft_strdup(pl_line);
	ft_makefigure(&*filler, pl_line);
}
