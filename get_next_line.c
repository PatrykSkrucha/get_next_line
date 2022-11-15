#include "get_next_line.h"
#include <string.h>

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
	int			check = 1;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = 1;
	line = malloc(1);
	line[0] = 0;
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
		if(!check)
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if(buffer[0]=='\0')
			{
				//free(buffer);
				free(line);
				return (NULL);
			}
			if(read_size >= 0)
				buffer[read_size] = '\0';
			if (read_size <= 0)
			{
				if (ft_strlen(line))
						return (line);
				free(buffer);
				free(line);	
				return (NULL);
			}
			check = 1;
		}
		if (check_for_nl(buffer) == -2 )
		{
			line = update_line(line, buffer, ft_strlen(buffer));
			free(buffer);
			buffer = NULL;
			return (line);
		}
		if (check_for_nl(buffer) >= 0)
		{		
			line = update_line(line, buffer, check_for_nl(buffer) + 1);
			update_buffer(buffer, check_for_nl(buffer) + 1);
			return (line);
		}
		if (check_for_nl(buffer) == -1 && check)
			line = update_line(line, buffer, ft_strlen(buffer));
		check = 0;
	}
}

//int	main()
//{
//	int		fd;

//	fd = open("./test.txt", O_RDONLY);
//	char *s = "";
//	int i = 1;

//	 while (s)
//	 { 
//		s = get_next_line(fd);
//		printf("line: [%i] %s",i, s);
//		free(s);
	
		
		
		
//		//s = get_next_line(fd);
//		//printf("%s",s);
//		//free(s);
//		//s = get_next_line(fd);
//		//printf("%s",s);
//		//free(s);
		
		
		
//	 	i++;	
//	 }
//	// puts(str);
//	//free(s);
	
//	close(fd);
//}