#include "main.h"
/**
 * execute_path - execute command path, its process
 * @args:arguments
 * Return:exit status
 */
int execute_path(char **args)
{
	int index = fork(), status;

	if (index == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}

