/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:28 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/07 18:48:54 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int check_for_nl(char *str, int buffer_size)
{
	int len = 0;
	while(str[len])
	{	
		if (str[len] == '\n' && len + 1 == buffer_size)
		{
			return (-1);
		}
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remaining;
	char 		*line;
	// int			BUFFER_SIZE = 5;
	
	int		nlpos;
	nlpos = 0;
	int read_size = 1;
	int check = 0;

	if(!buffer)
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
	while (read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (!read_size)
			return (NULL);
		buffer[read_size] = '\0';
		nlpos = check_for_nl(buffer, read_size);
		if (nlpos == -1)
		{
			line = ft_strdup(buffer);
			free(buffer);
			return (line);
		}
		else
		{

			buffer[0] = 'n';
			buffer[1] = 'i';
			buffer[2] = 'c';
			buffer[3] = '\0';
			return (buffer);
		}
	}
}

int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s",str);
	// puts(str);
	free(str);
	
	close(fd);
}