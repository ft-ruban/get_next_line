/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:10:28 by ldevoude          #+#    #+#             */
/*   Updated: 2025/01/16 15:11:28 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# endif
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif


# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef prout
#define prout
#include <stdio.h>
#endif

char    *get_next_line(int fd);
size_t	ft_strlen(const char *str);
void    *ft_calloc(size_t element_count, size_t element_size);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

