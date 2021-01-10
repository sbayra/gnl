#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c || s[i] == '\0')
            return ((char *)s + i);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)s + i);
    return (NULL);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*res;
    size_t	i;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
    {
        if (!(res = malloc(sizeof(char) * 1)))
            return (NULL);
        res[0] = '\0';
        return (res);
    }
    if (!(res = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    if (!res)
        return (0);
    while (i < len)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char	*ft_strdup(const char *s1)
{
    int		i;
    char	*res;

    i = 0;
    if (NULL == (res = malloc(sizeof(char) * ft_strlen(s1) + 1)))
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    unsigned int	len1;
    unsigned int	len2;
    unsigned int	i;
    unsigned int	j;
    char			*res;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    i = 0;
    j = -1;
    if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[++j])
        res[i++] = s2[j];
    res[i] = '\0';
    return (res);
}

void	ft_strclear(char **str)
{
	if(str != NULL && *str != NULL)
		ft_memdel((void**)str);
//
//	if(str != NULL && *str != NULL)
//	{	
//		free(*str);
//		*str = NULL;
//	}
}
void	ft_memdel(void **str)
{
	if(str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}
