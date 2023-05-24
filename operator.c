#include "shell.h"

/**
 * toHandleOperators - handles the operators
 * @strng: the string character
 * Return:
*/
int toHandleOperators(const char *strng)
{
	char *mmand;
	char *saveptr;
	int prev_status = 0;
	int opp = 1;
	char *trimmed_command;
	size_t lenth;
	int status;
	
	mmand = toStrtok_r((char *)strng, "&|", &saveptr);
	while (mmand != NULL)
	{
		trimmed_command = mmand;
		while (*trimmed_command == ' ' || *trimmed_command == '\t')
		{
			trimmed_command++;
		}
		
		lenth = toStringLength(trimmed_command);
		while (lenth > 0 && (trimmed_command[lenth - 1] == ' ' || trimmed_command[lenth - 1] == '\t'))
		{
			trimmed_command[lenth - 1] = '\0';
			lenth--;
		}
		status = handle_operator(trimmed_command);
		if (opp)
		{
			if (status != 0) 
			{
				return (status);
			}
		}
		else
		{
			if (status == 0)
				return (status);
		}
	}
	prev_status = status;
	/*mmand = toStrtok_r(NULL, "&|", &saveptr);*/
	/*opp = (mmand != NULL && mmand[0] == '&');*/
	return (prev_status);
}

/**
 * handle_operator - Handles the logic operators
 * @strng: The string colleted as input
 * Return: -1
*/
int handle_operator(const char *strng)
{
	pid_t pid;
	char *args[4];
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("failed");
		return -1;
	}
	else if (pid == 0)
	{
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = toStrdup(strng);
		args[3] = NULL;
		
		if (args[2] == NULL)
		{
			perror("failed");
			exit(EXIT_FAILURE);
		}
		execve(args[0], args);
		perror("failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("failed");
			return -1
		}
		if (WIFEXITED(status))
		{
			return (status);
		}
		else
		{
			return -1;
		}
	}
}
