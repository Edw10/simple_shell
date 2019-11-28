#include "shell.h"

char **path(int *c2)
{
	int i = 0, check2 = 1;
	char **paty;
	char *environ1;

	while (check2)
	{
		environ1 = _strdup(environ[i]);
		if (!_strncmp(strtok(environ1, "=:"), "PATH", 4))
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
				paty = realloc(paty, 8 * (*c2 + 1));
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
		free(environ1);
	}
	return(paty);
}
