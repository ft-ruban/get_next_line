#include "get_next_line.h"

#ifndef prout
# define prout
# include <stdio.h>
#endif

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open("file.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
	{
        printf("cc\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL && i < 2)
	{
		printf("%s", line);
		free(line);
		i++;
	}
	if (line)
		free(line);
	close(fd);
    line = NULL;
	fd = open("file.txt", O_RDONLY | O_CREAT);
	while ((line = get_next_line(fd)) != NULL && i < 5)
	{
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	if (line)
		free(line);
	return (0);
}
