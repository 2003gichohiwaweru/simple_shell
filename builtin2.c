#include "shell.h"

/**
 * toHandleExit- Handles the exit builtin
 * @var: variable
 * Return: Nothing
 */
void toHandleExit(char **var)
{
	int t = 0;
	const char *err;

	while (var[t] != NULL)
	{
		t++;
	}
	if (t > 2) 
	{
		err = "too many arguments\n";
		write(STDERR_FILENO, err, toStringLength(err));
	}
	else if (t == 2) 
	{
		exit(atoi(var[1])); 
	}
	else
	{
		exit(0); 
	}
}


/**
 * toHandleBuiltins - handles builtin functions
 * @var: tokenized variable
 * @env: value of the environment
 * Return: Nothing
 */
void toHandleBuiltins(char **var, char **env)

{
	if (toStrcmp(var[0], "exit") == 0)
	{
		toHandleExit(var);
	}
	else if (toStrcmp(var[0], "env") == 0)
	{
		toHandleEnv(env);
	}

	else if (toStrcmp(var[0], "cd") == 0)
	{
		toHandleCd(var);
	}

	else if (toStrcmp(var[0], "setenv") == 0)
	{
		toSetenv(var);
	}
	else if (toStrcmp(var[0], " unsetenv") == 0)
	{
		toUnsetenv(var);
	}
}
