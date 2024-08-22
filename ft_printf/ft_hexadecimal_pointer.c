/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:28:04 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/07/31 08:33:04 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	hex_helper_pointer(long unsigned int i)
{
	int		count;
	int		x;
	char	*l;

	l = "0123456789abcdef";
	count = 0;
	x = 0;
	if (i == 0)
		return (0);
	x = i % 16;
	count = hex_helper_pointer(i / 16);
	if (x >= 0 && x < 16)
	{
		write (1, &l[x], 1);
		count++;
	}
	return (count);
}

int	ft_hexadecimal_pointer(long unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	count = hex_helper_pointer(i) + 2;
	return (count);
}
