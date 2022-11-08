#include "get_next_line.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	x;

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

	while (src[len])
		len++;
	a = (char *)malloc(len + 1);
	if (a == NULL)
		return (NULL);
	ft_strlcpy(a, src, len + 1);
	return (a);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || len == 0)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	if (start > i)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i])
		i++;
	if (i < len)
		len = i;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}