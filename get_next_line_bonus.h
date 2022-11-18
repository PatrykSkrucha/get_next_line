/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:22:32 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/18 18:23:48 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

int		ft_strlen(char *str);
void	ft_strlcpy(char *dest, char *src, int size);
int		check_for_nl(char *str);
char	*get_next_line(int fd);
void	update_buffer(char *buffer, int nlpos);
char	*update_line(char *s1, char *s2, int len);
char	*read_line(char *buffer, int fd, char *line);

#endif