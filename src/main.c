/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:45:41 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:45:43 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../inc/filler.h"

void	ft_makestructzero(t_filler *filler)
{
	filler->box_init = 0;
	filler->start_y = 0;
	filler->start_x = 0;
	filler->enemy_x = 0;
	filler->enemy_y = 0;
	filler->my = '\0';
	filler->map_y = 0;
	filler->map_x = 0;
	filler->points = NULL;
	filler->figure_y = 0;
	filler->figure_x = 0;
	filler->if_stand = 0;
	filler->res_y = 0;
	filler->res_x = 0;
	filler->counter = 0;
	filler->bad_syt = 0;
}

void	ft_delfig(t_filler *filler)
{
	int counter;

	counter = 0;
	while (counter != filler->figure_x)
	{
		ft_strdel(&filler->figure[counter]);
		counter++;
	}
	ft_strdel(filler->figure);
	free(filler->figure_dot);
}

void	ft_findplayers(char *pl_line, t_filler *filler)
{
	get_next_line(0, &pl_line);
	filler->my = (pl_line[10] == '1') ? 'O' : 'X';
	filler->enemy = (pl_line[10] == '1') ? 'X' : 'O';
}

void	ft_makeend(t_filler *filler)
{
	filler->res_y = 0;
	filler->res_x = 0;
	filler->counter = 0;
}

int		main(void)
{
	t_filler	filler;
	char		*pl_line;

	ft_makestructzero(&filler);
	ft_findplayers(pl_line, &filler);
	while (get_next_line(0, &pl_line) > -1)
	{
		if (!pl_line)
			continue;
		if (!ft_strncmp(pl_line, "Plateau ", 8))
			ft_parsemap(&filler, pl_line);
		else if (!ft_strncmp(pl_line, "Piece ", 6))
		{
			ft_parsefigure(&filler, pl_line);
			ft_test(&filler);
			ft_delfig(&filler);
			ft_putnbr(filler.res_x);
			ft_putchar(' ');
			ft_putnbr(filler.res_y);
			ft_putchar('\n');
			ft_makeend(&filler);
		}
	}
	return (0);
}
