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
	char	*buffer = NULL;
	static char	*leftover;
	char 		*line;
	int			nlpos;
	int 		read_size;

	read_size = -1;
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
		if (leftover)
		{	
			// printf("\n\nbuffer after: [%s]", leftover);
			line = ft_strdup(leftover);
			// printf("\n\nline after dup: [%s]", line);
		}
		nlpos = check_for_nl(line, ft_strlen(line));
		if (nlpos && read_size != -1)
		{
			leftover = ft_strjoin(NULL, line, nlpos);
			line = ft_strjoin("", line, nlpos);
			return (line);
		}
		else
		{
			// printf("tu jestem");
			read_size = read(fd, buffer, BUFFER_SIZE);
			buffer[read_size] = '\0';
			if (read_size == 0)
			{
				free(buffer);
				free(line);
				return (NULL);
			}
			nlpos = check_for_nl(buffer, read_size);
			if (nlpos == -1)
			{
				line = ft_strjoin(line, buffer, ft_strlen(buffer));
				free(buffer);
				free(leftover);
				// printf("\nlane: [%s]", line);
				return (line);
			}
			else if (nlpos >= 0)
			{
				line = ft_strjoin(line, buffer, nlpos + 1);
				leftover = ft_strjoin(NULL, buffer, nlpos + 1);
				// printf("\nlane: [%s]", line);
				return (line);
			}
			else
				leftover = ft_strjoin(line, buffer, ft_strlen(buffer));
		}
	}
}

int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	char *s;
	int i = 0;

	while (i < 10)
	{
		printf("%s",get_next_line(fd));
		i++;	
	}
	// puts(str);
	free(s);
	
	close(fd);
}