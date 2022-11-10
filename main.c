#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	char *s;
	int i = 0;

	 while (i < 14)
	 {
		s = get_next_line(fd);
		printf("%s",s);
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
	free(s);
	
	close(fd);
}