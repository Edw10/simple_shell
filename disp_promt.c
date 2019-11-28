#include "shell.h"

int main()
{
	char *keywords = NULL, *aux = NULL;
	size_t buf = 0;
	int c2 = 0, c = 0, conteo = 0;
	int check = 1, error = 0;
	char **argv = NULL, **paty = NULL;

       	paty = path(&c2, &aux);
	while (check)
	{
		conteo++;
		if (isatty(STDIN_FILENO))
		{
		c = 0;
		write(1, "$ ", 2);
		}
		if ((getline(&keywords, &buf, stdin) == EOF))
		{
			if (isatty(STDIN_FILENO))
				write(1,"\n",1);
			break;
		}
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
			argv = _realloc(argv, 8 * (c), 8 * (c + 1));
			if (!argv)
		 	{
		 		write(1, "error", 5);
		 		return (-1);
		 	}
		 	argv[c] = strtok(NULL, " \f\n\r\t\v");

		}

		error = execute(argv, paty, c2, check, conteo);

		free(argv);
	}
	free(keywords);
	free(paty);
	free(aux);
	return(error);
}
