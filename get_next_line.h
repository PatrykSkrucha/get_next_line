#ifndef GET_THE_NEXT_LINE_H
# define GET_THE_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, int start, int len);

#endif