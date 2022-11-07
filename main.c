#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

int	main(int argc, char **argv)
{
	int fd;
	char *str = "";
	int n = 1;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;

	if (fd < 0)
	{
		printf("File opening unsuccessful!\n");
		return (-2);
	}

		str = get_next_line(fd);
		printf("%s",str);
		free (str);

	close(fd);
	// atexit(haha);
	return (0);
}
