/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:43:07 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/07 22:32:24 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_type(va_list ap, const char f_type)
{
	int	len;

	len = 0;
	if (f_type == 'c')
		len += ft_putchar((char)va_arg(ap, int));
	else if (f_type == 's')
		len += ft_printf_s(va_arg(ap, char *));
	else if (f_type == 'p')
		len = ft_printf_p(va_arg(ap, unsigned long long));
	else if (f_type == 'd' || f_type == 'i')
		len += ft_printf_n(va_arg(ap, int));
	else if (f_type == 'u')
		len = ft_printf_u(va_arg(ap, unsigned int));
	else if (f_type == 'x' || f_type == 'X')
		len = ft_printf_hex((va_arg(ap, unsigned int)), f_type);
	else if (f_type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	if (!format)
		return (0);
	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += printf_type(ap, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
