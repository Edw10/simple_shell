#include "shell.h"

int execute(char **argv, char **paty, int c2, int check)
{
	char *path;
	int aux = 1, i;


	(void)paty;


	if (access(argv[0], F_OK) && check)
	{
		i = 0;
		while(i <= c2)
		{
			path = _str_concat(paty[i], argv[0]);
			if (access(path, F_OK) && check)
			{
				aux = 0;
			}
			else
			{
				if (fork()==0)
				{
					execve(path, argv, environ);
					exit(0);
				}
				else
				{
					wait(NULL);
					aux = 1;
					i = c2 + 10;
				}
			}
			i++;
			free(path);
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
	return(0);
}
