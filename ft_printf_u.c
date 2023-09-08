/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:38 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/08 20:29:50 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_num_len(unsigned int num)
{
	int len;

	len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
//매개변수의 계산한 길이 받아오고 뒤에서 부터 값을 malloc으로 동적할당한 메모리에 넣어줌(문자열)
char *ft_uitoa(unsigned int n)
{
	char *num;
	size_t len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}
//최종출력 함수로 매개변수(unsigend int)의 값을 활용(문자열 출력, 문자열 길이 출력, 메모리free)
int ft_printf_u(unsigned int n)
{
	int len;
	char *num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len += ft_printf_s(num);
		free(num);
	}
	return (len);
}
