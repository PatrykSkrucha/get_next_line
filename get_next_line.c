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
#include "../libft/libft.h"

// char	*get_next_line(int fd)
// {
	
// }

// int check_for_nl(char *str)
// {
// 	int len = 0;
// 	while(str[len])
// 	{	
// 		if (str[len] == '\n')
// 			return (len);
// 		len+
// 	}
// 	return (0);
// }

int	main()
{
	// char	*c;
	// int		i;
	// int		fd;
	// int		nlpos;
	// nlpos = 0;
	// int sz = 20;
	// int check = 0;
	// int number = BUFFER_SIZE;

	// fd = open("test.txt", O_RDONLY);
	// i = 1;
	// c = (char*)malloc(number + 1 * sizeof(char));
	// while (i < number && !check && sz != 0)
	// {
	// 	read(fd, c, i);
	// 	if(check_for_nl(c))
	// 		break;	
	// 	i++;
	// }
	// close(fd);
	// free (c);
	ft_putchar_fd('a', 1);
}