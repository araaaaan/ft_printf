#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || \
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * m);
}
