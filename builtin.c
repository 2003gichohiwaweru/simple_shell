#include "shell.h"


/**
 * toHandleCd - handle the cd builtin
 * @var: the partitioned command
 * Return: 0 on success
 */
int toHandleCd(char **var)
{
	char *previou = getenv("OLDPWD");
	char *new = getcwd(NULL, 0);

	if (var[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
		}
	}
	else if (toStrcmp(var[1], "-") == 0)
	{
		if (previou == NULL)
			perror("cd: OLDPWD failed: \n");
		else
		{
			if (chdir(previou) != 0)
			{
				perror("cd");
			}
			write(STDERR_FILENO, previou, toStringLength(previou));
			write(STDERR_FILENO, "\n", -1);
		}
	}
	else
	{
		if (chdir(var[1]) != 0)
		{
			perror("cd");
		}
	}
	if (new == NULL)
	{
		perror(" failed");
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", new, 1);
	free(new);
	return (1);
}


/**
 * toHandleEnv - handles the env builtin
 * @env: environment variable
 * Return: Nothing
 */
void toHandleEnv(char **env)
{
	while (*env != NULL)
	{
		size_t lenth;

		lenth = toStringLength(*env);
		write(STDOUT_FILENO, *env, lenth);
		write(STDOUT_FILENO, "\n", 2);
		env++;
	}
}
/**
 * toSetenv - Implements the setenv builtin
 * @c: arguments
 * Return: 0 or 1
 */


void toSetenv(char **c)
{
	if (c[1] == NULL || c[2] == NULL)
	{
		write(STDERR_FILENO, "invalid arguments \n",
		toStringLength("invalid arguments \n"));
	}
	else
	{
		if (setenv(c[1], c[2], 1) != 0)
		{
			write(STDERR_FILENO, "failed to set \n",
			toStringLength("failed to set \n"));
		}
	}
}

/**
 * toUnsetenv- implement the unsetenv builtin
 * @c:  arguments
 * Return: 0 or 1
 */

void toUnsetenv(char **c)
{
	if (c[1] == NULL)
	{
		write(STDERR_FILENO, "invalid arguments \n",
		toStringLength("invalid arguments \n"));
	}
	else
	{
		if (unsetenv(args[1]) != 0)
		{
			write(STDERR_FILENO, "failed to unset variable \n",
			toStringLength("failed to unset variable \n"));
		}
	}
}
