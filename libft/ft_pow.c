/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:41:21 by amurakho          #+#    #+#             */
/*   Updated: 2018/04/16 10:41:22 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow(int number, size_t power)
{
	size_t	counter;
	size_t	res;

	res = 1;
	counter = 0;
	while (counter++ != power)
		res *= number;
	return (res);
}
