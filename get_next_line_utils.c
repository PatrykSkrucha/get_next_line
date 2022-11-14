#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return (counter);
}

void	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

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
}

char	*update_line(char *s1, char *s2, int len)
{
	char	*str;
	int		s1_len;

	s1_len = ft_strlen(s1);
	str = (char *)malloc(s1_len + len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, len + 1);
	free(s1);
	return (str);
}

void update_buffer(char *buffer, int nlpos)
{
	//char	*new_buffer;
	//int len = ft_strlen(buffer+nlpos);
int i=0;
	//new_buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	//if (!new_buffer)
	//	return (NULL);
	//ft_strlcpy(new_buffer, buffer + nlpos, len + 1);
	//free(buffer);
	while(buffer[nlpos+i])
	{
		buffer[i] = buffer[nlpos + i];
		i++;
	}

	buffer[i] = '\0';
	//return (new_buffer);
}

//void update_buffer(char *buffer, int nlpos)
//{
//	int		i;
	
//	i = 0;;
//	while(buffer[nlpos+i] != '\0')
//	{
//		buffer[i] = buffer[nlpos + i ];
//		i++;
//	}
//}