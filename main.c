#include "minishell.h"



void	exit_error(char *msg)
{
	printf("%s", msg);
	exit (EXIT_FAILURE);
}

int		ft_getchar()
{
	return (0);
}

int		ft_strcmp()
{
	return (0);
}

// void	*ft_realloc(void *ptr, size_t size)
// {
// 	void	*res;
// 	char	*copy;
// 	int		i;

// 	res = malloc(size);
// 	if (!res)
// 	{
// 		exit_error("allocation error");
// 	}
// 	while (ptr[i])
// 	{
// 		copy = (char)ptr;
// 	}
// 	return (res);
// }

char	*lsh_read_line(void)
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;

	bufsize = LSH_RL_BUFSIZE;
	position = 0;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (!buffer)
	{
		exit_error("allocation error\n");
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = 0;
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				exit_error("allocation error\n");
			}
		}
	}
}

char	**lsh_split_line(char *line)
{
	int		bufsize;
	int		position;
	char	**tokens;
	char	*token;

	bufsize = LSH_TOK_BUFSIZE;
	position = 0;
	tokens = (char **)malloc(bufsize * sizeof(char *));
	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				exit_error("allocation error\n");
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

int		lsh_launch(char	**args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("lsh");
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

int		lsh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int		lsh_execute(char **args)
{
	int		i;

	if (args[0] == NULL)
		return (1);
	i = 0;
	while (i < lsh_num_builtins())
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
		i++;
	}
	return (lsh_launch(args));
}

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);
		free(line);
		free(args);
	}
}

int		main(int argc, char **argv)
{
	lsh_loop();
	return EXIT_SUCCESS;
}
