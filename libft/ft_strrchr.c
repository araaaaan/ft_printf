#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*finder;

	finder = NULL;
	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (unsigned char)c)
			finder = (char *)s;
		s++;
	}
	return (finder);
}
