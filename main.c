#include "shell.h"


/**
 * main - Entry point of the program
 * @argc: argc
 * @argv: argv
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *st = NULL;
	int num;
	char *var[MAX_NUM_TOKENS];

	if (argc > 1 && toStrcmp(argv[0], "./hsh") == 0)
	{
		toFile(argc, argv);
		exit(0);
	}
	while (1)
	{
		if (isatty(0))
		{
			write(STDOUT_FILENO, "#cisgreatness$ ", 14);
		}
		st = toReadInput();
		if (st == NULL)
		{
			if (isatty(0))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(st);
			exit(0);
		}
		if (myStrchr(st, ';') != NULL)
			toHandlecolon(st);
		else
		{
			num = tokenize(st, var, MAX_NUM_TOKENS);
			if (num > 0 && toStrcmp(var[0], "alias") != 0)
				to_execute(var);
		}
		free(st);
	}
	return (0);
}

/**
 * toFile - opens shell scripts in non-intective mode
 * @argc: argc
 * @argv: argv
 * Return: 0 on success
 */
int toFile(int argc, char **argv)
{
	char *st = NULL;
	char *var[MAX_NUM_TOKENS];
	FILE *file;
	int num;
	size_t size_i = 0;


	if (argc != 2)
	{
		char error[] = "Usage: ";

		write(STDERR_FILENO, error, sizeof(error) - 1);
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, " NameFile\n", 11);
		exit(1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("fopen");
		exit(1);
	}

	while (mygetLine(&st, &size_i, *file) != -1)
	{
		num = tokenize(st, var, MAX_NUM_TOKENS);
		if (num > 0)
		{
			to_execute(var);
		}
	}
	fclose(file);
	return (0);
}
