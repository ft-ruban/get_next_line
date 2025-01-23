#include "get_next_line.h"

#ifndef prout
#define prout
#include <stdio.h>
#endif

int main (void)
{   
    char *line = "prot";
    int fd = open ("file.txt", O_RDONLY | O_CREAT);
    if (fd < 0)
    {
        return(1);
    }
    while((line = get_next_line(fd)) != NULL)
    {
    printf("%s", line);
    free(line);
    }
    close(fd);
    return (0);
}
