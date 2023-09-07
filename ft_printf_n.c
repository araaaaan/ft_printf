/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:07 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/07 16:36:49 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count(int num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	num;

	num = n;
	len = ft_count(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_printf_n(int num)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(num);
	len = ft_printf_s(nbr);
	free(nbr);
	return (len);
}
