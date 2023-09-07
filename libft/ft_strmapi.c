#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	f_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!f_str)
		return (NULL);
	while (s[i])
	{
		f_str[i] = f(i, s[i]);
		i++;
	}
	f_str[i] = '\0';
	return (f_str);
}
