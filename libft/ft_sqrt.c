/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:41:21 by amurakho          #+#    #+#             */
/*   Updated: 2018/04/16 10:41:22 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t val)
{
	size_t	counter;

	counter = 1;
	while (counter != val)
	{
		counter++;
		if (counter * counter > val)
			return (counter - 1);
		else if (counter == val)
			return (counter);
	}
	return (counter);
}
