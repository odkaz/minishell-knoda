#include "minishell.h"

int		lsh_echo(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"echo\"\n");
	}
	else
	{
		if (strcmp(args[1], "-n") == 0)
		{
			if (args[2] != NULL)
				printf("%s", args[2]);
			else
				fprintf(stderr, "lsh: expected argument to \"echo\"\n");
		}
		else
		{
			printf("%s\n", args[1]);
		}
	}
	return (1);
}
