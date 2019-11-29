#include "shell.h"

char **path(int *c2, char **environ10)
{
	int i = 0, check2 = 1;
	char **paty=NULL;
	char *environ1 = NULL;

	*c2 = 0;
	while (check2)
	{
		free(environ1);
		environ1 = _strdup(environ[i]);
		*environ10 = environ1;
		if (!_strncmp(strtok(environ1,"=:"), "PATH", 4))
		{
			paty = malloc(8);
			if (!paty)
			{
				write(1, "error1", 6);
				return (paty);
			}
			paty[*c2] = strtok(NULL, "=:");

			while (paty[*c2])
			{
				*c2 = *c2 + 1;
				paty = _realloc(paty, 8 * (*c2), 8 * (*c2 + 1));
				if (!paty)
				{
				 	write(1, "error2", 6);
				 	return (paty);
				}

				paty[*c2] = strtok(NULL, "=:");
			}
			check2 = 0;
		}
		i++;
	}

	return(paty);
}
