/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:54 by ldevoude          #+#    #+#             */
/*   Updated: 2025/01/16 15:12:30 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"
#include <stdio.h>
//function to read_tex
static char *stash;

char *write_and_save()
{
    int  i;
    int  j;
    char *buff;
    char *return_value;

    i = 0;
    while (stash[i] != '\n' && stash[i] != 0)
        i++;
    if (stash[i] == 0)
    {
        return_value = malloc ((i + 1) * (sizeof(char)));
        ft_strlcpy(return_value, stash, BUFFER_SIZE + 1);
        free (stash);
        return (return_value);
    }
    else
    j = i;
    buff = malloc((i + 1)*(sizeof(char)));
    if (!buff)
        return (NULL);
    //function to copy content of stash into return value
    //create a function to handle that?
    if (stash[i] == '\n')
    {
        while (stash[i] != 0)
            i++;
        if (!buff)
            return (NULL);
        strcpy(buff, stash); //find a way to truncate stash
        free (stash);
        stash = malloc((i - j +1)*(sizeof(char)));
        if (!stash)
            return (NULL);
        strcpy(stash,buff);
    }
    else 
       free (stash);
    //printf("buff = %s\n",return_value);
    //strcpy(buff,return_value);
    //printf("return_value : %s\n",return_value);
    return("a");
}

char *read_text(int fd)
{
    // variable char *buff_read ((static stash?))
    char *buff_read;

    buff_read = malloc ((BUFFER_SIZE + 1) * (sizeof(char)));
    stash = malloc ((BUFFER_SIZE + 1) * (sizeof(char)));
    if (!buff_read || !stash)
        return (NULL);
    //read (fd, buff_read, BUFFER_SIZE)
    if (read (fd, buff_read, BUFFER_SIZE) == -1)
        return (NULL);
    // stash = malloc (strlen stash + BUFFER_SIZE)
    stash = malloc (strlen (stash) + BUFFER_SIZE);
    if (!stash)
        return (NULL);
    // strcat stash, buff_read
    printf("buff_read : %s\n", buff_read);
    strcat (stash, buff_read);
    free (buff_read);
    printf("stash in read_text : %s\n", stash);
    return (stash);
}

char *get_next_line(int fd)
{
//variables. static *stash, char *returned_array.
    char    *returned_array;
//assign
    //fd = open ("file.txt", O_RDONLY | O_CREAT);
    if (fd < 0)
        return (NULL);
    stash = read_text(fd);
    printf("stash in get_next_line : %s\n", stash);
    return (returned_array = write_and_save ());    
}

