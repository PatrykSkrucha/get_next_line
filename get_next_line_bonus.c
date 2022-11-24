/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:13:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/19 14:44:11 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line[4096];

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	line[fd] = NULL;
	line[fd] = read_line(buffer[fd], fd, line[fd]);
	if (!ft_strlen(buffer[fd]) || !line[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line[fd]);
}
