/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:28:40 by arlee             #+#    #+#             */
/*   Updated: 2023/09/08 20:59:02 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//%x, %X에 관한 처리 (Unsigned hexadecimal integer)
int	ft_printf_hex(unsigned int num, const char format)
{
	int		len;

	len = 0;
	if (num > 15) //num >= 16
	{
		len += ft_printf_hex(num / 16, format);
		len += ft_printf_hex(num % 16, format);
	}
	else
	{
		if (num <= 9) // 0~9
			len += ft_putchar(num + '0');
		else
		{
			if (format == 'x') // %x 소문자
				len += ft_putchar(num - 10 + 'a');
			if (format == 'X') // %X 대문자
				len += ft_putchar(num - 10 + 'A');
		}
	}
	return (len);
}
