/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:59:43 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/07 17:21:10 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *format, ...);
int			printf_type(va_list ap, const char f_type);
int			ft_printf_n(int num);
int			ft_printf_p(unsigned long long ptr);
int			ft_printf_u(unsigned int n);
int			ft_printf_hex(unsigned int num, const char format);
int			ft_printf_s(char *str);
int			ft_printf_u(unsigned int n);
int			ft_putchar(char c);
size_t		ft_count(int num);
char		*ft_itoa(int n);
int			ft_putchar(char c);
int			ft_num_len(unsigned	int num);
char		*ft_uitoa(unsigned int n);
int			ft_put_ptr(unsigned long int num);
#endif