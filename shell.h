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

#endif
