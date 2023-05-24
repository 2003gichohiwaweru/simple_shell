#include "shell.h"


/**
 * toStrcant - Joins two strings
 * @s1: string concetenated
 * @s2: string joined to str1
 * Return: str1 and str2 combined
 */
char *toStrcant(char *s1, char *s2)
{
	int lenth1 = toStringLength(s1);
	int lenth2 = toStringLength(s2);

	char *answer = malloc(lenth1 + lenth2 + 1);

	if (answer == NULL)
	{
		perror("Memory allocation Failed");
		exit(1);
	}
	answer = toStrcpy(answer, s1);
	answer = toStrcat(answer, s2);
	return (answer);
}

/**
 * tostrdup - copies the contents of the input string to the memory
 * @string: copied string
 * Return: a pointer to the new string.
 */

char *toStrdup(const char *string)

{
	size_t lenth = toStringLength(string) + 1;
	char *mem = malloc(lenth);

	if (mem == NULL)
		return (NULL);
	memcpy(mem, string, lenth);
	return (mem);
}


/**
 * toMemcpy - copies bytes
 *  
 * @dest: a pointer to the destination buffer
 * @src: a pointer to the source buffer
 * @z: the bytes copied.
 * Return: void pointer to the destination buffer.
 */
void *toMemcpy(void *dest, const void *src, size_t z)
{
	size_t y;
    char *des = dest;
	const char *sr = src;

	for (y = 0; y < z; y++)
	{
		des[y] = sr[y];
	}
	return (dest);
}
/**
 * toRealloc - changes the size of the memory
 * @pointer: pointer to the previously allocated memory block
 * @zt: new size to allocate
 * Return: a void pointer to the newly allocated memory block.
 */
void *toRealloc(void *pointer, size_t zt)
{
	if (zt == 0)
	{
		free(pointer);
		return (NULL);
	}
	else if (pointer == NULL)
	{
		return (malloc(zt));
	}
	else
	{
		void *new_mem = malloc(zt);

		if (new_mem == NULL)
		{
			return (NULL);
		}
		toMemcpy(new_mem, pointer, zt);
		free(pointer);
		return (new_mem);
	}
}

/**
 * toPrintenv -  it print the variables environment
 * void: hence does not take any arguments
 * Return: 0 on success
 */

int toPrintenv(void)
{
	int y = 0;

	while ((environ[y]))
	{
		toPrintString(environ[y]);
		toPrintString("\n");
		y++;
	}

	return (0);
}
