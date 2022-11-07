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
	static char	*remaining;
	char *line;
	
	int		nlpos;
	nlpos = 0;
	int sz = 0;
	int check = 0;
	int buffer_size = 6;

	if(!buffer)
		buffer = (char*)malloc(buffer_size + 1 * sizeof(char));
	if(!buffer)
		return (NULL);
	while (!check)
	{
		sz = read(fd, buffer, buffer_size);
		printf("%zu\n",strlen(buffer));
		// nlpos = check_for_nl(buffer, buffer_size);
		// if (nlpos == -1)
		// {
		// 	check = 1;
			return (buffer);
		}
		// else
		// {

		// 	buffer[0] = 'n';
		// 	buffer[1] = 'i';
		// 	buffer[2] = 'c';
		// 	buffer[3] = '\0';
		// 	return (buffer);
		// }
	// }
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