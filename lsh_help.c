#include "minishell.h"

int		lsh_help(char **args)
{
	int		i;

	if (args[1] != NULL)
		exit_error("help function does not take argument");
	printf("knoda's LSH\n");
	printf("type program names and arguments, and hit enter\n");
	printf("the folloing are in builtin\n");
	i = 0;
	while (i < lsh_num_builtins())
	{
		printf("%s\n", builtin_str[i]);
		i++;
	}
	printf("use the man command for information on other programs\n");
	return (1);
}
