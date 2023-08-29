
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



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
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
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

int ft_printf_s(char *str)
{
	int i;
	
	i = 0;
	if(str == NULL)
	{
		write(1,"(null)",6);
		return(6);
	}
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_printf_u(unsigned int num)
{
	int len;
	char *nbr;

	len = 0;
	if(num == 0)
		len += write(1,"0",1);
	else
	{
		nbr = ft_itoa(num);
		len += ft_printf_s(nbr);
		free(nbr);
	}
	return (len);
}


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


int ft_printf_c(const char c)
{
	write(1, &c, 1);
	return (1);
}


int printf_type(const char f_type, va_list *f_list)
{
	int len;

	len = 0;
	if (f_type == 'c')
		len += ft_printf_c(va_arg(*f_list, int));
	else if (f_type == 's')
		len += ft_printf_s(va_arg(*f_list, char *));
	// else if	(f_type == 'p')
	// 	return (ft_printf_p(va_arg(*f_list, char *)));
	else if (f_type == 'd' || f_type == 'i')
		len += ft_printf_n(va_arg(*f_list, int));
	else if (f_type == 'u')
		len += ft_printf_u(va_arg(*f_list, unsigned int));
	// else if (f_type =='x' || f_type == 'X')
	// 	return (ft_printf_x(va_arg(*f_list, unsigned int)));
	// else if (f_type == '%')
		// return (ft_printf_percent(va_arg(*f_list, int)));
	return (len);
}
int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;


	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += printf_type(format[i+1], &ap);
			i++;
		}
		else
			len += ft_printf_c(format[i]);
		i++;
	}
	
	printf("length: %d", len);
	va_end(ap);

	return (len);
}


int main()
{

	char c = 'A';
	char str[] = "Hello";
	char *str2 = NULL;
	int n = 123;
	unsigned int un = -10;
	ft_printf("%u\n", un);
	printf("%u", un);
	return 0;
}

