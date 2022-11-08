#include "get_next_line.h"
#include <stdio.h>

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	x;

	x = 0;
	while (src[x])
		x++;
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

char	*ft_strdup(char *src)
{
	char	*a;
	int		len;

	len = 0;
	while (src[len])
		len++;
	a = (char *)malloc(len + 1);
	if (a == NULL)
		return (NULL);
	ft_strlcpy(a, src, len + 1);
	return (a);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	char	*str;
	int	s1_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2 + size));
	if (s2 == NULL)
		return (ft_strdup(s1 + size));
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	str = (char *)malloc(s1_len + size + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, size + 1);
	return (str);
}
