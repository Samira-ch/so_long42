/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:47:12 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/07/31 08:31:54 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	hex_helper(unsigned int i, char *l)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	if (i == 0)
		return (0);
	x = i % 16;
	count = hex_helper(i / 16, l);
	if (x >= 0 && x < 16)
	{
		write (1, &l[x], 1);
		count++;
	}
	return (count);
}

int	ft_put_hexadecimal(unsigned int i, char c)
{
	char	*l;
	int		count;

	if (i == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (c == 'x')
	{
		l = "0123456789abcdef";
		count = hex_helper(i, l);
	}
	else if (c == 'X')
	{
		l = "0123456789ABCDEF";
		count = hex_helper(i, l);
	}
	return (count);
}
