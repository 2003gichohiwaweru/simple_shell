#include "shell.h"
#include <unistd.h>
#include <stdlib.h> 

#define ENOMEN 12
#define EINVAL 128
//#define INIT_BUF_SIZE 128

/**
 * toAllocateBuff - allocates memory
 * @buff_s: the size of the memomry
 * Return: Address of the memory allocated 
 */


char *toAllocateBuff(size_t buff_s)
{
	char *buff;
    buff = (char *) malloc(buff_s); //allocates the buff using malloc

	if (buff == NULL)
	{
		errno = ENOMEM;
		return (NULL);   
	}
	return (buff);
}
/**
 * mygetLine - my getline
 * @ptr: memory for storing the strings
 * @size: Size of the buffer
 * @fd: The file stream descriptor the string is stored
 * Return: -1 or number of char's read
*/


ssize_t mygetLine(char **ptr, size_t* size, int fd)
{
    ssize_t tchar = 0;
    ssize_t rd = 0;
    size_t otherSize;
    char *otherptr;

    if (ptr == NULL || size == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    if (*ptr == NULL)
    {
        *ptr = (char*)malloc(INIT_BUF_SIZE);
        if (*ptr == NULL)
        {
            return -1;
        }
        *size = INIT_BUF_SIZE;
    }

    while (1)
    {
        if (tchar >= *size - 1) {           
            otherSize = *size + INIT_BUF_SIZE;
            otherptr = (char*)toRealloc(*ptr, otherSize);
            if (otherptr == NULL)
            {
                free(*ptr);
                *ptr = NULL;
                return -1;
            }
            *ptr = otherptr;
            *size = otherSize;
        }

        
        rd = read(fd, *ptr + tchar, 1); // Read characters into the buffer
        if (rd == -1)
        {
            free(*ptr);
            *ptr = NULL;
            return -1;
        } else if (rd == 0)
        {
            break;  //  breaks the loop to read the file at the end of the file
        }
        tchar = tchar + rd;
        
        if ((*ptr)[tchar - 1] == '\n')
        {
            break;
        }
    }

   
    (*ptr)[tchar] = '\0';

    return (tchar);
}
