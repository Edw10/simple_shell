#ifndef SHELL
#define SHELL

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


#endif
