#include "shell.h"

/**
 * myStrchr - it is a customed strchr function
 * @strng: string character to be entered
 * @z: the character to searh
 * Return: Nothing
*/
char *myStrchr(const char *strng, int z) 
{
    while (*strng != '\0') {
        if (*strng == z) {
            return (char *)strng;
        }
        strng++;
    }

    if (*strng == z) {
        return (char *)strng;
    }

    return NULL;
}

/**
 * toSetenviron - clone of setenv
 * @name: variable name
 * @val: new variable value
 * @o_wr: checks if variable exists or not
 * Return: 0 or -1
 */
int toSetenviron(const char *name, const char *val, int o_wr)
{
	int res;
	char *var;

	var = (char *)malloc(toStringLength(name) + toStringLength(value) + 2); //2 for = and /0
	if (!var)
	{
		return (-1);
	}

	toStrcpy(var, name); //compares the variable name
	toStrcat(var, "="); //joins the value with the =
	myStrcat(var, val);

	if (mygetLine(name))
	{
		if (o_wr)
		{
			res = toputenviron(var);
		}
		else
		{
			res = 0;
		}
	}
	else
	{
		res = toputenviron(var);
	}

	if (res != 0)
	{
		free(var);
	}

	return (var);
}

/**
 * toUnsetenviron - customized of unset function
 * @name: variable name
 * Return: 0 or -1
 */
int toUnsetenviron(const char *name)
{
	int j, k, lenth;
	char **en; 
    char **nen;

	if (!name || !*name)
	{
		return (-1);  
	}

	en = environ;

	if (!en || !*en)
	{
		return (-1);
	}

	lenth = toStringLength(name);

	nen = (char **)malloc(sizeof(char *)   + 1);
	if (!nen)
	{
		return (-1);
	}

	for (j = 0, k = 0; en[j]; j++)
	{
		if (toStrrcmp(en[j], name, lenth) != 0 || en[j][lenth] != '=')
		{
			nen[k++] = en[j];
		}
	}

	nen[k] = NULL;

	environ = nen;

	return (0);
}

/**
 * toputenviron - copy of a putenviron
 * @strng: value pair to be added to env
 * Return: 1 or 0
 */
int toputenviron(char *strng)
{
	int res = 0;
	char **nen = NULL;
	int j, k;

	
	if (!strng || !*strng || myStrchr(strng, '=') == NULL)
	{
		return (-1);
	}

	nen = (char **)malloc((char *) + 2);
	if (!nen)
	{
		return (-1);
	}


	for (j = 0, k = 0; environ[j] != NULL; j++)
	{
		if (toStrrcmp(environ[j], strng, myStrchr(strng, '=') - strng) != 0)
		{
			nen[k++] = environ[j];
		}
		else
		{
			res = 1;
		}
	}


	nen[k++] = strng;

	nen[k] = NULL;

	environ = nen;

	return (res);
}
