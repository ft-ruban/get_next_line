// #include "get_next_line.h"

// #ifndef prout
// # define prout
// # include <stdio.h>
// #endif

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	i = 0;
// 	fd = open("file.txt", O_RDONLY | O_CREAT);
// 	if (fd < 0)
// 	{
//         printf("cc\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL && i < 2)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	if (line)
// 		free(line);
// 	close(fd);
//     line = NULL;
// 	fd = open("file.txt", O_RDONLY | O_CREAT);
// 	while ((line = get_next_line(fd)) != NULL && i < 5)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	if (line)
// 		free(line);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:22:16 by tarini            #+#    #+#             */
/*   Updated: 2025/01/10 19:16:56 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("[%s]", line);
		free(line);
	}
	printf("[%s]", line);
	close(fd);
	return (0);
}