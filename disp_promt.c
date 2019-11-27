#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define TRUE 1 // variables to return error states //
#define FAIL -1


int main()
{
	char *keywords = NULL;
	size_t buf = 0;
	int c = 0, i = 0;
	int check = 1, check2 = 1;
	char **argv = NULL, **paty = NULL;

	while (strtok(environ[i], "=:") && check2)
	{
		if (!strncmp(environ[i], "PATH", 4))
		{
			paty = malloc(8);
			if (!paty)
			{
				printf("error");
				return (-1);
			}
			paty[c] = strtok(NULL, "=:");
			while (paty[c])
			{
				c++;
				paty = realloc(paty, 8 * (c + 1));
				if (!paty)
				{
				 	printf("error");
				 	return (-1);
				}
				paty[c] = strtok(NULL, "=:");
			}
		check2 = 0;
		}
		i++;
	}



	while (check)
	{
		c = 0;
		printf("$ ");
		getline(&keywords, &buf, stdin);
		argv = malloc(8);
		if (!argv)
		{
			printf("error");
			return (-1);
		}
		argv[0] = strtok(keywords, " \f\n\r\t\v");
		if(argv[0])
			check = strcmp(argv[0], "exit");
		while (argv[c])
		{
			c++;
			argv = realloc(argv, 8 * (c + 1));
			if (!argv)
		 	{
		 		printf("error");
		 		return (-1);
		 	}
		 	argv[c] = strtok(NULL, " \f\n\r\t\v");

		}



		if (access(argv[0], F_OK) && check)
		{
			printf("the command is not found\n");
		}
		else
		{
			if (fork()==0)
			{
				execve(argv[0], argv, environ);
			}
			else
			{
				wait(NULL);
			}
		}
		free(argv);
	}
	free(keywords);
	free(paty);
	return(0);
}
