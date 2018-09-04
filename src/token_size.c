/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:41:19 by amurakho          #+#    #+#             */
/*   Updated: 2018/08/26 14:41:21 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/filler.h"

size_t	ft_numlen(char *size)
{
	size_t counter;

	counter = 0;
	while (size[counter] != ' ' && size[counter] != ':')
		counter++;
	return (counter);
}

void	ft_size(t_filler *filler, char *size, int is_map)
{
	char	*st_x;
	char	*st_y;
	size_t	num_counter;

	size += 6;
	if (is_map)
		size += 2;
	num_counter = ft_numlen(size);
	st_x = (char*)malloc(sizeof(st_x) * num_counter + 1);
	st_x = ft_strncpy(st_x, size, num_counter);
	st_x[num_counter] = '\0';
	size += num_counter + 1;
	num_counter = ft_numlen(size);
	st_y = (char*)malloc(sizeof(st_y) * num_counter + 1);
	st_y = ft_strncpy(st_y, size, num_counter);
	st_y[num_counter] = '\0';
	ft_ismap(is_map, filler, st_x, st_y);
	ft_strdel(&st_y);
	ft_strdel(&st_x);
}

void	ft_ismap(int is_map, t_filler *filler, char *st_x, char *st_y)
{
	if (is_map)
	{
		filler->map_x = ft_atoi(st_x);
		filler->map_y = ft_atoi(st_y);
	}
	else
	{
		filler->figure_x = ft_atoi(st_x);
		filler->figure_y = ft_atoi(st_y);
	}
}
