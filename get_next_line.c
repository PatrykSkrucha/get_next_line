#include "get_next_line.h"

int check_for_nl(char *str)
{
	int len;

	if (!str)
		return (-3);
	len = 0;
	while(str[len])
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;
	int 		read_size;
	char		*temp;
	int			check = 1;

	read_size = 1;
	line = ft_strdup("");
	if (!buffer)
	{
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		buffer[0] = '\0';
		check = 0;
	}
	if(!buffer)
		return (NULL);
	while (1)
	{
		if (check_for_nl(buffer) == -2 )
		{
			temp = ft_strdup(line);
			free(line);
			temp = ft_strjoin(line, buffer, ft_strlen(buffer));
			buffer = NULL;
			free(buffer);
			check = 0;
			return (temp);
		}
		if (check_for_nl(buffer) >= 0)
		{	
			temp = ft_strdup(line);
			free(line);
			line = ft_strjoin(temp, buffer, check_for_nl(buffer) + 1);
			free(temp);
			temp = ft_strdup(buffer);
			free(buffer);
			buffer = ft_strjoin(NULL, temp, check_for_nl(temp) + 1);
			free(temp);
			check = 1;
			return (line);
		}
		if (check_for_nl(buffer) == -1 && check)
		{
			temp = ft_strdup(line);
			free(line);
			line = ft_strjoin(temp, buffer, ft_strlen(buffer));
			free(temp);
			check = 0;
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		if (read_size != 0)
			check = 1;
		if (read_size <= 0)
		{
			if (ft_strlen(line))
				{
					
					free(buffer);
					return (line);
				}
			return (NULL);
		}
	}
}

int	main()
{
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	char *s = "";
	int i = 1;

	 while (s)
	 { 
		s = get_next_line(fd);
		printf("line: [%i] %s",i, s);
		free(s);
	
		
		
		
		//s = get_next_line(fd);
		//printf("%s",s);
		//free(s);
		//s = get_next_line(fd);
		//printf("%s",s);
		//free(s);
		
		
		
	 	i++;	
	 }
	// puts(str);
	//free(s);
	
	close(fd);
}