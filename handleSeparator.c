#include "shell.h"
/**
 * toDelimetize - splits string into parts using a strtok function
 * @strng: input string that needs to be tokenized.
 * @var: holds the tokens
 * @var_max: max no of tokens that can be extracted from the input string
 * @delim: delimiter string
 * Return: number of tokens
 */
int toDelimetize(char *strng, char **var, int var_max, char *delim)
{
	int num = 0;
	char *t = strtok(strng, delim);

	while (t != NULL && num < var_max)
	{
		var[num] = t;
		num++; 
		t = strtok(NULL, delim); 
	}
	var[num] = NULL;
	return (num); 
}

/**
 * toHandlecolon - handles ";" separator
 * @strng: string that is tokenized
 * Returns: Nothing
 */
void toHandlecolon(char *strng)
{
    pid_t pid;
    int k;
    int tus;
    char *kom[MAX_NUM_TOKENS];
    char *args[MAX_ARGS];

    int num_tokens = toDelimetize(strng, kom, MAX_NUM_TOKENS, ";");

    for (k = 0; k < num_tokens; k++)
    {
    	int num_args = toDelimetize(kom[k], args, MAX_ARGS, " \t\n");
        if (num_args > 0)
        {
            pid = fork();
            if (pid == 0)
            {
            	execvp(args[0], args);
            	perror("Failed to execute");
            	exit(EXIT_FAILURE);
            }
            else if (pid < 0)
            {
            	perror("Fork failed");
            	exit(EXIT_FAILURE);
            }
            else
            {
                do {
                	waitpid(pid, &tus, WUNTRACED);
                } 
				while (!WIFEXITED(tus) && !WIFSIGNALED(tus));
            }
        }
    }
}


/**
 * token_lenth - calculates the length of a token 
 * @strng: string character
 * @delim: no of delimetre
 * Return: length of the delims
*/

int token_lenth(char *strng, char *delim)
{
    int lent = 0;
    while (*strng && strchr(delim, *strng) == NULL)
    {
    	strng++;
    	lent++;
    }
	return lent;
}
/**
 * toCounttokens - ounts the number in a string
 * @strng: string character
 * @delim: Number of Delims
*/

int toCounttokens(char *strng, char *delim)
{
    int var = 0;
    int lenth = 0;
    int ndex;

    lenth = toStringLength(strng);

    for (ndex = 0; ndex < lenth; ndex++)
    {
        if (strng[ndex] != *delim)
        {
            var++;
            ndex += token_lenth(strng + ndex, delim) - 1;
			
			}
    }

    return var;
}
