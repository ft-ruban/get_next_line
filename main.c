#include "get_next_line.h"
#include <stdio.h>

int main (void)
{
    int i = 0;
    int fd = open ("file.txt", O_RDONLY | O_CREAT);
    while(i != 3)
    {
    printf("%s",get_next_line(fd));
    i++;
    }
    //get_next_line(fd);
    return (0);
}
