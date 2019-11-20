#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FAIL -1
int main()
{
	char *keywords, *aux = "exit\0", *tok = NULL;
	size_t buf = 0;
	int check = 1;
	do 
	{
		printf("$ ");
		getline(&keywords, &buf, stdin);
		tok = strtok(keywords, "\n");
		check = strcmp(tok, aux); 
		printf("%s\n", keywords);
		if(check == 0)			
			return(FAIL);

	} while(TRUE) ;
	free(keywords);
	return(0);
}

