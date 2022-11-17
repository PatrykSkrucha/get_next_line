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

char	*update_line(char *s1, char *s2, int len)
{
	char	*str;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	str = malloc(s1_len + len + 1);
	if (str == NULL)
		return (NULL);
	while (i < s1_len && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + i] = '\0';
	free(s1);
	return (str);
}

void update_buffer(char *buffer, int nlpos)
{
	int i;
	
	i = 0;
	while (buffer[nlpos + i])
	{
		buffer[i] = buffer[nlpos + i];
		i++;
	}

	buffer[i] = '\0';
}

int check_for_nl(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{	
		if (str[len] == '\n' && len + 1 == ft_strlen(str))
		{
			return (-2);
		}
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

char	*get_line(int read_size, char *buffer, int fd, int check, char *line)
{
	while (read_size > 0)
	{
		if (check)
		{
			if (check_for_nl(buffer) == -2 )
			{
				line = update_line(line, buffer, ft_strlen(buffer));
				buffer[0] = 0;
				return (line);
			}
			if (check_for_nl(buffer) >= 0)
			{		
				line = update_line(line, buffer, check_for_nl(buffer) + 1);
				update_buffer(buffer, check_for_nl(buffer) + 1);
				return (line);
			}
			if (check_for_nl(buffer) == -1)
				line = update_line(line, buffer, ft_strlen(buffer));
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
		check = 1;
		buffer[read_size] = '\0';
	}
	return (line);
}