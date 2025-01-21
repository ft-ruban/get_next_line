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

#include "string.h"
#include "get_next_line.h"

//function to read_tex
static char *stash;

char *write_and_save()
{
    int  i;
    int  j;
    char *buff;
    char *return_value;

    i = 0;
    j = 0;
    while (stash[i] != '\n' || stash[i] != 0)
        i++;
    return_value = malloc ((i + 1) * (sizeof(char)));
    if (!return_value)
        return (NULL);
    //function to copy content of stash into return value

    //create a function to handle that?
    if (stash[i] == '\n')
    {
        j = i;
        while (stash[i] != 0)
            i++;
        buff = malloc((i - j + 1)*(sizeof(char)));
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
    return(return_value);
}

int is_next_line()
{
    if (strchr(stash, '\n'))
        return (1);
    else 
    return (0);
}

char *read_text(int fd)
{
    // variable char *buff_read ((static stash?))
    char *buff_read;

    buff_read = malloc ((BUFFER_SIZE + 1) * (sizeof(char)));
    if (!buff_read)
        return (NULL);
    //read (fd, buff_read, BUFFER_SIZE)
    if (read (fd, buff_read, BUFFER_SIZE) == -1)
    //handle error when read return -1
        return (NULL);
    // stash = malloc (strlen stash + BUFFER_SIZE)
    stash = malloc (strlen (stash) + BUFFER_SIZE);
    if (!stash)
        return (NULL);
    // strcat stash, buff_read
    strcat (stash, buff_read);
    free (buff_read);
    return (stash);
}

char *get_next_line(int fd)
{
//variables. static *stash, char *returned_array.
    char    *returned_array;
//assign
    fd = open ("file.txt", O_RDONLY | O_CREAT);
    if (fd < 0)
        return (NULL);
// while loop (condition = read the content of stash to see if there is any \n?)
    while(1)
    {
        //function to read the text until the buffer size is reached
        stash = read_text(fd);
        if (is_next_line() != 0)
            break;
    }
    return (returned_array = write_and_save ());    
}

