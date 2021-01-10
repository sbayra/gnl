#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFF_SIZE 1
# define FD_SIZE 4096

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

void		ft_strclear(char **str);
void		ft_memdel(void **str);
size_t		ft_strlen(const char *s);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char	    *ft_strdup(const char *s1);
char	    *ft_strchr(const char *s, int c);
char	    *ft_strjoin(char const *s1, char const *s2);
int		    get_next_line(int fd, char **line);

#endif
