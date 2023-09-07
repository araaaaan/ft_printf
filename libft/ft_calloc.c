#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(count * size);
	if (tmp == 0)
		return (NULL);
	ft_memset (tmp, 0, size * count);
	return (tmp);
}
