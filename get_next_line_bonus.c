/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:13:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/18 18:21:28 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line[1024];

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
	if (!ft_strlen(buffer[fd]))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line[fd]);
}

//int	main()
//{
//	int		fd;
//	int		fd1;
//	fd = open("test.txt", O_RDONLY);
//	fd1 = open("read_error.txt", O_RDONLY);
//	char *s = "";
//	int i = 1;
//	//printf("fd: %i", fd);
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
//		s = get_next_line(fd1);
//		printf("line: [%i] %s",i, s);
//		free(s);
//		s = get_next_line(fd);
//		printf("line: [%i] %s",i, s);
//		free(s);
//		s = get_next_line(fd1);
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
//	close(fd1);
//}