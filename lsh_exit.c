#include "minishell.h"

int		lsh_exit(char **args)
{
	if (args[1] != NULL)
		exit_error("exit function does not take argument");
	return (0);
}
