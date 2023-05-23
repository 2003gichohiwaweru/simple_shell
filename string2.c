#include "shell.h"


/**
 * toStrcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: the diffrence of the strings
 */
int toStrcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * toStrrcmp - checks if two strings are equal
 * @st1: first string
 * @st2: second string
 * @z: compares the first n characters of st1 and st2.
 *
 * Return: 0 on sucess
 */
int toStrrcmp(const char *st1, const char *st2, size_t z)
{
	size_t y; /*STRING SIZE*/

	for (y = 0; y < z; y++)
	{
		if (*st1 == '\0' || *st1 != *st2)
		{
			return (*st1 - *st2);
		}
		st1++;
		st2++;
	}
	return (0);
}

/**
 * toStrcat - concatenates two strings
 * @dest: destination of the string
 * @src: string constant
 * Return: cancated string
 */
char *toStrcat(char *dest, const char *src)
{
	char *des = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (des);
}

/**
 * toStrcpy - copies contents of one string to another string
 * @dest:  destination
 * @src: copied string
 * Return: copied string
 *
 */

char *toStrcpy(char *dest, const char *src)
{
	char *des = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (des);
}
