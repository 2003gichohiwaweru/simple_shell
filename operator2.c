#include "shell.h"


/**
 * toStrtok_r - splits a string into tokens based on delimiters
 * @str: the string to be split
 * @delim: the delimiters
 * @saveptr: pointer to a char pointer to maintain context between calls
 * Return: a pointer to the next token, or NULL if no more tokens are found
 */
char *toStrtok_r(char *strng const char *delim, char **saveptr)
{
	char *tok;
	size_t strng_lenth = toStringLength(strng);
	size_t delim_lenth = toStringLength(delim);
	size_t j, k;
	int is_delim;
	
	if (strng != NULL)
	{
		*saveptr = strn;
	}
	if (*saveptr == NULL)
    {
        return NULL;
    }

    tok = *saveptr;
    j = 0;

    while (j < strng_lenth)
    {
        is_delim = 0;

        for (k = 0; k < delim_lenth; k++)
        {
            if (tok[j] == delim[k])
            {
                is_delim = 1;
                break;
            }
        }

        if (is_delim)
        {
            tok[j] = '\0';
            j++;
            break;
        }

        j++;
    }

    if (j == strng_lenth)
    {
        *saveptr = NULL;
    }
    else
    {
        *saveptr = &tok[j];
    }

    return tok;
}i
