#include "libft.h"

size_t	ft_counter(char const *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (ret);
}

char	**ft_malfree(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*ft_malncpy(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (!n)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	save;
	size_t	counter;

	i = 0;
	j = 0;
	counter = ft_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!str)
		return (NULL);
	while (i < counter && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		save = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		str[i] = ft_malncpy(&s[save], j - save);
		if (str[i++] == NULL)
			return (ft_malfree(str));
	}
	str[i] = NULL;
	return (str);
}
