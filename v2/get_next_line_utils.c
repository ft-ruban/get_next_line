/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:10:16 by ldevoude          #+#    #+#             */
/*   Updated: 2025/01/29 16:25:14 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*ptr;
	size_t	i;
	size_t	total_size;

	total_size = element_count * element_size;
	i = 0;
	ptr = malloc(total_size);
	if (ptr == 0)
		return (NULL);
	while (i != total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*char ft_strjoin(char consts1, char const s2)
{
    size_t len1 = (s1 != NULL) ? ft_strlen(s1) : 0;
    size_t len2 = (s2 != NULL) ? ft_strlen(s2) : 0;
    charstr;
    size_t i;

    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
        return NULL;
    i = 0;
    if (s1 != NULL) {
        while (s1)
            str[i++] =s1++;
    }
    if (s2 != NULL) {
        while (s2)
            str[i++] =s2++;
    }
    str[i] = '\0';
    return str;
}*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1); //breakbrokebroken
	if (!str)
		return (NULL);
	while (s1[j] != 0)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
