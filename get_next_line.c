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
	return (-2);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	static int	leftover;
	char 		*line;
	int			nlpos;
	int 		read_size;

	read_size = 1;
	nlpos = 0;
	line = "";
	// leftover =

	if (!buffer)
	{
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		buffer[0] = '\0';
	}
	if(!buffer)
		return (NULL);
	while (read_size != 0)
	{
		if (ft_strlen(buffer) > 1)
		{	
			printf("\n\nbuffer after: [%s]", buffer);
			line = ft_strdup(buffer);
			printf("\n\nline after dup: [%s]", line);
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (!read_size)
		{
			free(buffer);
			return (line);
		}
		buffer[read_size] = '\0';
		nlpos = check_for_nl(buffer, read_size);
		if (nlpos == -1)
		{
			
			line = ft_strdup(buffer);
			free(buffer);
			return (line);
		}
		else if (nlpos >= 0)
		{
			line = ft_strjoin(line, buffer, nlpos + 1);
			buffer = ft_strjoin(NULL, buffer, nlpos +1);
			printf("\n\nbuffer before: [%s]", buffer);
			return (line);
		}
		else
			line = ft_strdup(buffer);
	}
}

int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	char *s;
	int i = 0;

	while (i < 3)
	{
		printf("%s",get_next_line(fd));
		i++;	
	}
	// puts(str);
	free(s);
	
	close(fd);
}