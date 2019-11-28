#include "shell.h"

int execute(char **argv, char **paty, int c2, int check, int conteo)
{
	char *path = NULL;
	int aux = 0, is = 0, i;

	(void) conteo;
	if (argv[0])
	{
		while(argv[0][is])
			is++;
	if (access(argv[0], F_OK) && check)
	{
		i = 0;
		while(i <= c2)
		{
			path = _str_concat(paty[i], argv[0]);
						if (access(path, F_OK) && check)
			{
				aux = 127;
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
					aux = 0;
					i = c2 + 10;
				}
			}
			free(path);
			i++;
		}
		if(aux)
		{
			write(2, "./hsh: ",7);
			print_number(conteo);
			write(2, ": ", 2);
			write(2, argv[0], is);
			write(2, ": not found\n", 12);
		}
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
	}
	return(aux);

}
