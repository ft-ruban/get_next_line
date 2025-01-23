#include "get_next_line.h"

char *newline_cleaner(char *buff)
{
    int i;
    int j;
    char *temp;

    i = 0;
    j = 0;
    while (buff[i] != 0 && buff[i] != '\n')
        i++;
    if(!buff[i])
    {
        free (buff);
        return(NULL);
    }
    temp = ft_calloc((ft_strlen (buff) - i + 1) , sizeof(char));
    if (!temp)
        return(NULL);
    i++;
    while (buff[i] != 0)
    {
        temp[j] = buff[i];
        i++;
        j++;
    }
    free (buff);
    return (temp);
}

char *fill_returned_line(char *buff, char *returned_line)
{
    int i;

    i = 0;
    if (!buff[i])
    return(NULL);
    while (buff[i] != 0 && buff[i] != '\n')
        i++;
    returned_line = ft_calloc((i + 2), (sizeof(char)));
    if (!returned_line)
        return(NULL);
    i = 0;
    while (buff[i] != 0 && buff[i] != '\n')
    {
    returned_line[i] = buff[i];
    i++;
    }
    if(buff[i] && buff[i] == '\n')
        returned_line[i] = '\n';
    return (returned_line);
}

char *merge_then_free(char *dest, char *src)
{
    char *new_str;

    new_str = ft_strjoin(dest, src);
    if(!new_str)
        return (NULL);
    free (dest);
    return (new_str);
}
char *read_content_then_stock (int fd, char *returned_buff)
{
    char *buff;
    int bytes_len;

    if (!returned_buff)
        returned_buff = ft_calloc(1, 1);
    buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
    if (!buff)
        return (NULL);
    bytes_len = 1;
    while (bytes_len > 0)
    {
        bytes_len = read(fd, buff, BUFFER_SIZE);
        if (bytes_len == -1)
        {
            free (buff);
            return (NULL);
        }
        buff[bytes_len] = 0;
        returned_buff = merge_then_free(returned_buff, buff);
        if (ft_strchr (buff, '\n'))
            break;
    }
        free(buff);
        return (returned_buff);
}
//start of the function, it also check in cases of errors init variables tht would be usefull later
char *get_next_line(int fd)
{
   static char *buff;
    char *returned_line;

    returned_line = (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 , 0) < 0)
        return (NULL);
    buff = read_content_then_stock(fd, buff);
    if (!buff)
        return (NULL);
    returned_line = fill_returned_line (buff, returned_line);
    if(!returned_line) {
        free(buff);
        return (NULL);
    }
    buff = newline_cleaner(buff);
    if(buff == NULL)
        return (returned_line);
    return (returned_line);
}
