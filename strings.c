#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str:string whose length to check
 * Return:length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}
/**
 * string_comparison - performs comparison of two strings
 * @str1:first string
 * @str2:second string
 * Return:negative  if str1 < str2,
 * positive if str1 > str2,
 * zero if str1 == str2.
 */
int string_comparison(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? - 1 : 1);
}
/**
 * start_with_needle - checks if needle starts with haystack
 * @haystack:string search
 * @needle:the substring to find
 * Return:address of next character of haystack or NULL
 */
char *start_with_needle(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * strcat - concatenates two string
 * @destination:destination buffer
 * @source:source buffer
 * Return:pointer to destination buffer
 */
char *_strcat(char *destination, char *source)
{
	char *result = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (result);
}

