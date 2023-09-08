/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:07 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/08 20:32:02 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//libft에서 사용한 itoa사용(int to ascii), 음수처리, 최대값처리, 메모리할당이 관건
int ft_printf_n(int num)
{
	int len;
	char *nbr;

	len = 0;
	nbr = ft_itoa(num);
	len = ft_printf_s(nbr);
	free(nbr);
	return (len);
}
