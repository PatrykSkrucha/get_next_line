/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:32:44 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/18 17:59:48 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	line = NULL;
	line = read_line(buffer, fd, line);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

//int	main()
//{
//	int		fd;
//	fd = open("test.txt", O_RDONLY);
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