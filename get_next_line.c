#include "get_next_line.h"

static int obrezaniye(char **str, char **line, int ret)
{
    int len;
    char *temp;

    len = 0;
    while((*str)[len] != '\n' && (*str)[len] != '\0')
    {
        len++;
    }
	if((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		temp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = temp;
//		if ((*str)[0] == '\0')
			ft_strclear(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strclear(str);
	}
    if (ret == 0)
        return (0);
    else
	    return (1);
}

//static int	output(char **str, char **line, int ret, int fd)
//{
//	if (ret < 0)
//		return (-1);
//	else
//		return (obrezaniye(&str[fd], line, ret));
//}

int get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	int ret;
	static char *str[FD_SIZE];
	char *temp;

	if(fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	while((ret = read(fd, buff, BUFF_SIZE)) > 0) {
        buff[ret] = '\0';
        if (!str[fd]) {
            str[fd] = ft_strdup(buff);
        }
        else{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		    }
		if(ft_strchr(str[fd], '\n'))
			break;
	}
    if (ret < 0)
        return (-1);
    else if(buff[0] == '\0')
    {
        *line = ft_strdup("");
        return (0);
    }
    else
        return (obrezaniye(&str[fd], line, ret));
}