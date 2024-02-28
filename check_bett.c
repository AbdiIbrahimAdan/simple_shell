#include "main.h"
/**
 * check_empty_line - check if existing a empty line
 * @buff:check line
 * Return:0 or 1
 */
int check_empty_line(char *buff)
{
	int index;

	for (index = 0; buff[index] != '\0'; index++)
	{
		if (buff[index] != ' ')
			return (0);
	}
	return (1);
}


