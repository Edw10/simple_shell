#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"


int main()
{
	char *keywords = NULL, *machete = "/";
	size_t buf = 0;
	int c2 = 0, c = 0, i = 0;
	int check = 1, check2 = 1, aux=1;
	char **argv = NULL, **paty = NULL;

	while (strtok(environ[i], "=:") && check2)
	{
		if (!_strncmp(environ[i], "PATH", 4))
		{
			paty = malloc(8);
			if (!paty)
			{
				write(1, "error1", 6);
				return (-1);
			}
			paty[c2] = strtok(NULL, "=:");

			while (paty[c2])
			{
				c2++;
				paty = realloc(paty, 8 * (c2 + 1));
				if (!paty)
				{
				 	write(1, "error2", 6);
				 	return (-1);
				}

				paty[c2] = strtok(NULL, "=:");
			}
		check2 = 0;
		}
		i++;
	}



	while (check)
	{
		c = 0;
		write(1, "$ ", 2);
		getline(&keywords, &buf, stdin);
		argv = malloc(8);
		if (!argv)
		{
			write(1, "error", 5);
			return (-1);
		}
		argv[0] = strtok(keywords, " \f\n\r\t\v");
		if(argv[0])
			check = _strcmp(argv[0], "exit");
		while (argv[c])
		{
			c++;
			argv = realloc(argv, 8 * (c + 1));
			if (!argv)
		 	{
		 		write(1, "error", 5);
		 		return (-1);
		 	}
		 	argv[c] = strtok(NULL, " \f\n\r\t\v");

		}



		if (access(argv[0], F_OK) && check)
		{
			i = 0;

			while(i <= c2)
			{
				machete = _str_concat(paty[i], argv[0]);
				if (access(machete, F_OK) && check)
				{
					aux = 0;
				}
				else
				{
					if (fork()==0)
					{
						execve(machete, argv, environ);
					}
					else
					{
						wait(NULL);
						aux = 1;
						i = c2 + 10;
					}
				}
				i++;
				free(machete);

			}
			if(!aux)
				write(1, "command not found\n", 18);
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
