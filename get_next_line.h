#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_read_file(char *str, int fd);
int			ft_strchrn(char *str);
char		*ft_strdup(const char *src);
int			ft_until_n(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500                                                                                               
#  define OPEN_MAX 5000

# endif

#endif
