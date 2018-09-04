/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:46:24 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/29 16:46:25 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include <mlx.h>
# include "../../inc/filler.h"
# include "../../libft/libft.h"
# define WIDTH 	1200
# define HEIGHT 1200
# define ESC	53

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	size_t	linenb;
	int		start;
	int		firststep;
	int		**mapxyz;
	int		resfirst;
	int		ressec;
	int		takemap;
	char	*sres_y;
	char	*sres_x;
	char	*mapjoin;
	char	**map;
}				t_mlx;

void			ft_getmap_xy(t_mlx *e, size_t y, size_t x);
void			ft_put_pixel(t_mlx *e);
#endif
