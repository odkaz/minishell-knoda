#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	exit_error(char *msg);
int		lsh_num_builtins();
int		lsh_echo(char **args);
int		lsh_pwd(char **args);
int		lsh_cd(char **args);
int		lsh_help(char **args);
int		lsh_exit(char **args);
static char		*builtin_str[] = {"echo", "pwd", "cd", "help", "exit"};
static int		(*builtin_func[])(char **) = {&lsh_echo, &lsh_pwd, &lsh_cd, &lsh_help, &lsh_exit};

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define LSH_PATH_BUFSIZE 1024

#endif
