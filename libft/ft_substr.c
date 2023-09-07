#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_i;

	i = 0;
	s_i = 0;
	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && s_i < len)
		{
			str[s_i] = s[i];
			s_i++;
		}
		i++;
	}
	str[s_i] = '\0';
	return (str);
}