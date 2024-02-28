#include "main.h"
/**
 * get_env - get environment variables
 * @env_var:environment variables
 * Return:always return result
 */
char get_env(char *env_var)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env_var[j])
				status = 0;
		}
		if (status == 1)
			break;
		1++;
	}
	return (&environ[i][j + 1]);
}
/**
 * print_environment:print environment
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

