#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>



#define EXIT -3
#define MAX_NUM_TOKENS 100
#define INIT_BUF_SIZE 1024
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 100
#define MAX_PATH_HEADER2 512

#define MAX_ARGS 100
#define MAX_PATH 1024
#define DELIMITERS " \t\r\n\a"

extern char **environ;


/**
 * struct alia_st - alias variables linked list
 *@name: alias name
 *@val: alias value
 * @next: pointer to the next node
 */

typedef struct alia_st
{
	char *name;
	char *val;
	struct alia_st *next;
} alia_list;

/**
 * struct linked_list - A struct to define a linked list.
 * @direto:  directory path.
 * @next: A pointer to the next node
 */

typedef struct linked_list
{
	char *direto;
	struct linked_list *next;
} listst;

/* Handles Inputs */


/* string.c */
char *toReadInput();
int toStringLength(const char *strng);
void toPrintString(char *strng);
void toWrite(char *strng);

/* string1.c */

int toStrcmp(const char *str1, const char *str2);
int toStrrcmp(const char *st1, const char *st2, size_t z);
char *toStrcat(char *dest, const char *src);
char *toStrcpy(char *dest, const char *src);

/* main.c */
int tokenize(char *st, char **var, int var_max);
char *check_command(char **var);
void to_execute(char **var);
int toFile(int argc, char **argv);

/* memory.c */
char *toStrcant(char *s1, char *s2);
char *toStrdup(const char *string);
void *toMemcpy(void *dest, const void *src, size_t z);
void *toRealloc(void *pointer, size_t zt);
int toPrintenv(void);

/* Builtin Helpers */

/* builtin.c */
int toHandleCd(char **var);
void toHandleEnv(char **env);
void toSetenv(char **c);
void toUnsetenv(char **c);

/* builtin2.c */
void toHandleExit(char **var);
void toHandleBuiltins(char **var, char **env);

/* handleSemicolon */
int toDelimetize(char *strng, char **var, int var_max, char *delim);
void toHandlecolon(char *strng);
int token_lenth(char *strng, char *delim);
int toCounttokens(char *strng, char *delim);

/* getLine.c */
ssize_t mygetLine(char **ptr, size_t *size, int fd);
char *toAllocateBuff(size_t buff_s);

/* enviroment.c*/
char *myStrchr(const char *strng, int z);
int toSetenviron(const char *name, const char *val, int o_wr);
int toUnsetenviron(const char *name);
int toputenviron(char *strng);

/* operators.c */
int handle_operator(const char *string);
int toHandleOperators(const char *string);
/* operators2.c */
char *myStrtok_r(char *strng const char *delim, char **saveptr);





#endif
