/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:17 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/07 22:32:29 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long int num)
{
	int		len;

	len = 0;
	if (num > 15)
	{
		len += ft_put_ptr(num / 16);
		len += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar(num + '0');
		else
			len += ft_putchar(num - 10 + 'a');
	}
	return (len);
}

int	ft_printf_p(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_ptr(ptr);
	}
	return (len);
}
