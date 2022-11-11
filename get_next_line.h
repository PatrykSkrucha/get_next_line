#ifndef GET_THE_NEXT_LINE_H
# define GET_THE_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

int	ft_strlen(char *str);
void	ft_strlcpy(char *dest, char *src, int size);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2, int size);
int check_for_nl(char *str);
char	*get_next_line(int fd);

#endif