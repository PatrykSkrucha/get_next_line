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
	static char	*buffer;
	char 		*line;
	
	int		nlpos;
	nlpos = 0;
	int read_size = 1;
	line = "";

	if(!buffer)
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
	while (read_size != 0)
	{
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
			if(line)
				line = ft_strjoin(line, buffer, nlpos);
			else
			{
				line = (char *)malloc((nlpos + 2) * sizeof(char));
				ft_strlcpy(line, buffer, nlpos + 1);
			}
			buffer = ft_strjoin(NULL, buffer, nlpos);
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
	char *s = get_next_line(fd);
	printf("%s",s);
	s = get_next_line(fd);
	printf("%s",s);
	s = get_next_line(fd);
	printf("%s",s);
	// puts(str);
	free(s);
	
	close(fd);
}