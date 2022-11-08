#ifndef GET_THE_NEXT_LINE_H
# define GET_THE_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2, int size);
void	ft_strlcpy(char *dest, char *src, int size);
int	ft_strlen(char *str);

#endif