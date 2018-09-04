/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 15:05:47 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 15:05:51 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

void	get_line(char **line, int *x_counter, int *l_counter, int is_map)
{
	get_next_line(0, &*line);
	if (is_map)
		*line += 4;
	*x_counter += 1;
	*l_counter = 0;
}
