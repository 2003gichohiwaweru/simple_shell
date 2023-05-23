#include "shell.h"

/**
 * toReadInput - reads user input from stdin using getline()
 * Return: Returns input from stdout
 */

char *toReadInput()
{
	char *strng = NULL;
	size_t size_i = 0;
	ssize_t rd;

	rd = getline(&strng, &size_i, stdin);
	if (rd == -1)
	{
		free(strng);
		return (NULL);
	}
	if (rd > 0 && strng[rd - 1] == '\n')
	{
		strng[rd - 1] = '\0';
	}
	return (strng);
}

/**
 * toStringLength -  gets the lenght of a string
 * @strng: string whose length is determined
 * Return: Length of the string
 */
int toStringLength(const char *strng)
{
	int lenth = 0;

	if (strng == NULL)
	{
		return (0);
	}

	while (strng[lenth] != '\0')
	{
		lenth++;
	}
	return (lenth);
}

/**
 * toPrintString - writes/print string to stdin
 * @strng: string written
 */

void toPrintString(char *strng)
{
	size_t lenth;

	if (strng != NULL)
	lenth = toStringLength(strng);
	write(STDOUT_FILENO, strng, lenth); /*writes out to the stdout*/
}

/**
 * toWrite - writes string to stderr
 * @strng: Error message printed
 */
void toWrite(char *strng)
{
	size_t lenth;

	if (strng != NULL)

	lenth = toStringLength(strng);

	write(STDERR_FILENO, strng, lenth); /*WRITES ON THE STRERROR*/
}
