#include "shell.h"
/**
 * copy_string - copy the string
 * @destination:the destination string to be copied 
 * @source:source string
 * @n:amount of character to copied
 * Return:concatenated string
 */
char *copy_string(char *destination, char *source, int n)
{
	int i, j;
	char *str = destination;
	
	i = 0;
	while (source[i] != '\n' && i < n - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (str);
}
/**
 * _strncat - concatenates the strings
 * @destination:first string
 * @source:second string
 * @n:amount of bytes be used
 * Return:concatenated string
 */
char *_strncat(char *destnation, char *source, int n)
{
	int i, j;
	char *str = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' &&  j < n)
	{
		destination[i] = source [j];
		i++;
		j++;
	}
	if (j < n)
		destination[i] = '\0';
	return (str);
}
/**
 * string_character - locates character in a string
 * @str:string to be parsed
 * @c:character to look for
 * Return:pointer to point to the memory area of string location
 */
char *string_character(char *str, char *c)
{
	do {
		if (*str == c)
			return (str);
	}while (*str++ != '\0');
	return (NULL);
}

