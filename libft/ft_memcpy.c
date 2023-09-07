#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dt;
	unsigned char	*s;
	size_t			i;

	i = 0;
	dt = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dt == s)
		return (dt);
	while (i < len)
	{
		dt[i] = s[i];
		i++;
	}
	return (dst);
}
