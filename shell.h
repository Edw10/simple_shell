#ifndef SHELL
#define SHELL
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * struct argv - singly linked list
 * @arg: argument
 * @next: points to the next node
 *
 * Description: list the arguments to execute the commands
 */
typedef struct arg
{
	char *arg;
	struct arg *next;
} arg_l;

int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_str_concat(char *s1, char *s2);
char **path(int *c2, char **environ10);
int execute(char **argv, char **paty, int c2, int check);
char *_strdup(char *str);

#endif
