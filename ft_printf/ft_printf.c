/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:33:52 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/07/31 08:31:40 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_helper(va_list args, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		len += ft_putnbr_unsignedint(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_put_hexadecimal(va_arg(args, unsigned int), str);
	else if (str == 'p')
		len += ft_hexadecimal_pointer(va_arg(args, long unsigned int));
	return (len);
}

int	in_set(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && in_set (str[i + 1], "cspdiuxX%"))
		{
			i++;
			if (str[i] == '%')
				len += ft_putchar('%');
			else
				len += ft_helper(args, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}	
