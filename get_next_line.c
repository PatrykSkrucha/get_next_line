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
	int			control;

	control = 1;
	read_size = -1;
	line = ft_strdup("");

	if (!buffer)
	{
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		buffer[0] = '\0';
	}
	if(!buffer)
		return (NULL);
	while (1)
	{
		if (check_for_nl(buffer) >= 0)
		{	
			temp = ft_strdup(line);
			free(line);
			line = ft_strjoin(temp, buffer, check_for_nl(buffer) + 1);
			temp = ft_strdup(buffer);
			free(buffer);
			buffer = ft_strjoin(NULL, temp, check_for_nl(temp) + 1);
			free(temp);
			return (line);
		}
		if (check_for_nl(buffer) == -2 )
		{
			temp = ft_strdup(line);
			line = ft_strjoin(temp, buffer, ft_strlen(buffer));
			free(temp);
			free(buffer);
			return (line);
		}
		if (check_for_nl(buffer) == -1 && control)
		{
			temp = ft_strdup(line);
			free(line);
			line = ft_strjoin(temp, buffer, ft_strlen(buffer));
			free(temp);
			control = 0;;
		}
		else
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			buffer[read_size] = '\0';
			if (read_size == 0)
			{
				if (ft_isprint(buffer[0]))
				{
					temp = ft_strdup(line);
					free(line);
					line = ft_strjoin(temp, buffer, ft_strlen(buffer));
					free(buffer);
					free(temp);
					return (line);
					
				}
				if (ft_strlen(line) >= BUFFER_SIZE)
					{
						free(buffer);
						return (line);
					}
				return (NULL);
			}
		}
	}
}

