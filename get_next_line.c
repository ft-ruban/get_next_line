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

#include "get_next_line.h"

//function to read_text
void read_text(int fd)
{
    // variable char *buff_read ((static stash?))

    //read (fd, buff_read, BUFFER_SIZE)
    //handle error when read return -1
    // stash = malloc (strlen stash + BUFFER_SIZE)
    // strcat stash, buff_read
}

char *get_next_line.c(int fd)
{
//variables. static *stash, char *returned_array.
static char *stash;
char    *returned_array;

//assign
stash = VOID;
//fd = open assign value of fd with open function
// if fd < 0) return error

// make a if condition to handle errors or weird inputs

// while loop (condition = read the content of stash to see if there is any \n?) 
    {

    //stash = read_text function to read the text until the buffer size is reached
    //if (function is_next_line(static char *stash) != 0
        //break
    }
    
}

