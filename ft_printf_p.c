/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:17 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/08 20:19:46 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//16진수로 출력, 각 자리수 출력 후 결과 len누적 후 길이 반환 (16부터 0x 붙음, 40 == 0x28)
int	ft_put_ptr(unsigned long long num) //unsigned long int에서 변경 (사용이유? 포인터는 메모리주소를 나타내므로 포인터비트수를 다르기위해(64비트 8바이트)
{
	int		len;

	len = 0;
	if (num > 15) //16~
	{
		len += ft_put_ptr(num / 16);
		len += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9) //0-9
			len += ft_putchar(num + '0');
		else
			len += ft_putchar(num - 10 + 'a'); //10-15
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
