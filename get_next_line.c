#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_size;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = 1;
	line = NULL;
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		buffer[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	line = get_line(read_size, buffer, fd, line);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		buffer = 0;
	}
	return (line);
}

//int	main()
//{
//	int		fd;
//	fd = open("test.txt", O_RDONLY);
//	char *s = "";
//	int i = 1;
//	printf("fd: %i", fd);
//	if(fd < 0)
//	{
//		printf("File opening unsuccessful!\n");
//		return (-2);
//	}
//	 while (s)
//	 { 
//		s = get_next_line(fd);
//		printf("line: [%i] %s",i, s);
//		free(s);
//		//s = get_next_line(fd);
//		//printf("line: [%i] %s",i, s);
//		//free(s);
//		//s = get_next_line(fd);
//		//printf("line: [%i] %s",i, s);
//		//free(s);
//		//s = get_next_line(fd);
//		//printf("line: [%i] %s",i, s);
//		//free(s);	
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