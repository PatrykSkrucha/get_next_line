/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:33:28 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/18 18:16:46 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return (counter);
}

char	*update_line(char *old_line, char *buffer, int len)
{
	char	*new_line;
	int		old_line_size;
	int		i;

	i = 0;
	old_line_size = ft_strlen(old_line);
	new_line = malloc(old_line_size + len + 1);
	if (new_line == NULL)
		return (NULL);
	while (i < old_line_size && old_line[i])
	{
		new_line[i] = old_line[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		new_line[old_line_size + i] = buffer[i];
		i++;
	}
	new_line[old_line_size + i] = '\0';
	free(old_line);
	old_line = NULL;
	return (new_line);
}

void	update_buffer(char *buffer, int nlpos)
{
	int	i;

	i = 0;
	while (buffer[nlpos + i])
	{
		buffer[i] = buffer[nlpos + i];
		i++;
	}
	buffer[i] = '\0';
}

int	check_for_nl(char *str)
{
	int	len;

	len = 0;
	while (str[len])
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

char	*read_line(char *buffer, int fd, char *line)
{
	int	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		if (ft_strlen(buffer) && check_for_nl(buffer) == -2)
		{
			line = update_line(line, buffer, ft_strlen(buffer));
			buffer[0] = 0;
			return (line);
		}
		if (ft_strlen(buffer) && check_for_nl(buffer) >= 0)
		{		
			line = update_line(line, buffer, check_for_nl(buffer) + 1);
			update_buffer(buffer, check_for_nl(buffer) + 1);
			return (line);
		}
		if (ft_strlen(buffer) && check_for_nl(buffer) == -1)
			line = update_line(line, buffer, ft_strlen(buffer));
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
	}
	return (line);
}
