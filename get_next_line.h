#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
char	*get_line(int read_size, char *buffer, int fd, char *line);

#endif