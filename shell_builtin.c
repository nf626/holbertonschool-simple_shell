#include "shell.h"

<<<<<<< HEAD
/** Function declaration */
int ss_ls(char **argv);
int ss_exit(char **argv);
int ss_env(char **argv);
int ss_printenv(char **argv);
int ss_echo(char **argv);

/** List of builtin commands, followed by their corresponding functions. */
char *ss_str[] = {
	"ls",
	"exit",
	"env",
	"printenv",
	"echo"
};

int (*ss_func[])(char **) = {
	&ss_ls,
	&ss_exit,
	&ss_env,
	&ss_printenv,
	&ss_echo
=======
/**
 * builtin_list - Pointer to list of strings.
 * 
 * Return: String matched to user/terminal input.
 */
char *builtin_list[] = {
  "exit",
  "env",
};
/**
 * builtin_func - Function pointer to list the functions to get from builtin_list.
 * 
 * Return: builtin_list command.
 */
int (*builtin_func[])(char **) = {
  &ss_exit,
  &ss_env
>>>>>>> nigel_shell
};
/**
 * ss_num - Get the number of characters in string.
 *
 * Return: Total number of strings. 
 */
int ss_num(void)
{
<<<<<<< HEAD
	return (sizeof(ss_str) / sizeof(char *));
}

/** Builtin function implementation */
/** list contents of a directory */
int ss_ls(char **argv)
{
	(void)argv;
	pid_t child_pid, wpid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		char *ls_input[] = {"ls", NULL};
		if (execve("/bin/ls", ls_input, environ) == -1)
		{
			perror("Error:");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("Error:");
	}
	else
	{
		do {
			wpid = waitpid(child_pid, &status, WUNTRACED);
			(void)wpid;
		} while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
	}
	
	return (1);
}
/** exit */
int ss_exit(char **argv)
{
	(void)argv;
	exit(EXIT_SUCCESS);
	return (0);
=======
  return (sizeof(builtin_list) / sizeof(char *));
}
/** 
 * ss_exit - Exit input to terminate shell.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_exit(char **argv)
{
  if (strcmp(argv[0], "exit") == 0)
    {
      exit(EXIT_SUCCESS);
    }
      return (0);
>>>>>>> nigel_shell
}
/** 
 * ss_env - Print shell environment.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_env(char **argv)
{
<<<<<<< HEAD
	unsigned int i = 0;
	(void)argv;
	int len = 0;
	while (environ[i] != NULL)
	{
		while (environ[i][len] != '\0')
		{
			len++;
		}
		
		write(STDOUT_FILENO, environ[i], len);
		
		write(STDOUT_FILENO, "\n", 1);
		
		i++;
	}
	return (1);
}
/** print "printenv" */
int ss_printenv(char **argv)
{
	ss_env(argv);
	return (1);
}

/* print "echo" */
int ss_echo(char **argv)
{
	for (int i = 1; argv[i] != NULL; i++) /* Start from 1 to skip "echo" */
	{
		write(STDOUT_FILENO, argv[i], strlen(argv[i]));
		if (argv[i + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1); /* Add a space between arguments */
		}
	}
	write(STDOUT_FILENO, "\n", 1); /* Newline at the end */
	return (1);
=======
  if (strcmp(argv[0], "env") == 0)
    {
      print_env();
    }
  return (0);
>>>>>>> nigel_shell
}
