/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsignedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:09:06 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/07/31 08:32:02 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_putnbr_unsignedint(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putchar('0');
	}
	else if (n == 4294967295)
	{
		count += ft_putchar('4');
		count += ft_putnbr_unsignedint(294967295);
	}
	else
	{
		if (n >= 10)
		{
			count += ft_putnbr(n / 10);
			count += ft_putnbr(n % 10);
		}
		else
		{
			count += ft_putchar(n + '0');
		}
	}
	return (count);
}
