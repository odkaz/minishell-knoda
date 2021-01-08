#include "minishell.h"

int		lsh_pwd(char **args)
{
	char	path[LSH_PATH_BUFSIZE];

	if (args[1] != NULL)
		exit_error("exit function does not take argument");
	getcwd(path, LSH_PATH_BUFSIZE);
	printf("path > %s\n", path);
	return (1);
}
