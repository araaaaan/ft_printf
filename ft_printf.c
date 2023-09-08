/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:43:07 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/08 20:49:00 by aaaaaran         ###   ########.fr       */
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
		len += ft_putchar((char)va_arg(ap, int)); //포인터를 자료형 사이즈만큼 이동 후 목록에서 인자 가져옴(가져온 int값을 char로 형변환)
	else if (f_type == 's')
		len += ft_printf_s(va_arg(ap, char *));
	else if (f_type == 'p')
		len = ft_printf_p(va_arg(ap, unsigned long long)); //메모리주소는 8바이트(64비트에서)
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
// 제일 처음 단계의 함수, prift()의 기능구현, format은 고정인자, ...은 가변인자
int	ft_printf(const char *format, ...)
{
	va_list	ap;	//va_list, va_start, va_arg, va_copy, va_end는 매크로
	int		len;
	int		i;

	if (!format)
		return (0);
	va_start(ap, format);	//va_list(가변인자 리스트포인터를 가리키는 포인터)를 첫주소로 초기화
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += printf_type(ap, format[i]); //format[i+1]
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap); // 사용종료 선언
	return (len);
}
