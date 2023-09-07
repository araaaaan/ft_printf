/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:28:40 by arlee             #+#    #+#             */
/*   Updated: 2023/09/07 17:21:59 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int num, const char format)
{
	int		len;

	len = 0;
	if (num > 15)
	{
		len += ft_printf_hex(num / 16, format);
		len += ft_printf_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				len += ft_putchar(num - 10 + 'a');
			if (format == 'X')
				len += ft_putchar(num - 10 + 'A');
		}
	}
	return (len);
}
