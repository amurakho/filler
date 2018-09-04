/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:57:36 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:57:42 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "../libft/libft.h"

typedef struct {
	int				x;
	int				y;
	char			symbol;
	size_t			distance;
}					t_point;

typedef struct {
	int				x;
	int				y;
	char			symbol;
}					t_figure_dot;

typedef struct {
	int				bad_syt;
	int				res_x;
	int				res_y;
	char			my;
	char			enemy;
	int				box_init;
	int				enemy_x;
	int				enemy_y;
	int				map_x;
	int				map_y;
	t_point			*points;
	int				start_x;
	int				start_y;
	t_figure_dot	*figure_dot;
	int				figure_x;
	int				figure_y;
	char			**box;
	char			**figure;
	int				if_stand;
	int				counter;
}					t_filler;

void				ft_test(t_filler *filler);
void				ft_parsemap(t_filler *filler, char *pl_line);
void				ft_ismap(int is_map, t_filler *filler,
					char *st_x, char *st_y);
void				get_line(char **line, int *x_counter,
					int *l_counter, int is_map);
void				ft_size(t_filler *filler, char *size, int is_map);
void				ft_makedistance(t_filler *filler);
void				ft_makestartcoord(t_filler *filler,
					int x_counter, int y_counter);
void				ft_editenemy(t_filler *filler, int counter);
void				ft_makeendcoord(t_filler *filler,
					int x_counter, int y_counter);
void				ft_findstart(t_filler *filler);
void				ft_parsefigure(t_filler *filler, char *pl_line);
size_t				ft_iftest(t_filler *filler, size_t distance);
void				ft_test(t_filler *filler);

#endif
