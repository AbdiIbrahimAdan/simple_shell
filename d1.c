1,76c1,71
< #include "shell.h"
< 
< /**
<  * interactive - returns true if shell is interactive mode
<  * @info: struct address
<  *
<  * Return: 1 if interactive mode, 0 otherwise
<  */
< 
< int interactive(info_t *info)
< {
< 	return (isatty(STDIN_FILENO) && info->readfd <= 2);
< }
< 
< /**
<  * is_delim - checks if character is a delimeter
<  * @c: the char to check
<  * @delim: the delimeter string
<  * Return: 1 if true, 0 if false
<  */
< 
< int is_delim(char c, char *delim)
< {
< 	while (*delim)
< 		if (*delim++ == c)
< 			return (1);
< 	return (0);
< }
< 
< /**
<  * _isalpha - checks for alphabetic character
<  * @c: The character to input
<  * Return: 1 if c is alphabetic, 0 otherwise
<  */
< 
< int _isalpha(int c)
< {
< 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
< 		return (1);
< 	else
< 		return (0);
< }
< 
< /**
<  * _atoi - converts a string to an integer
<  * @s: the string to be converted
<  * Return: 0 if no numbers in string, converted number otherwise
<  */
< 
< int _atoi(char *s)
< {
< 	int i, sign = 1, flag = 0, output;
< 	unsigned int result = 0;
< 
< 	for (i = 0; s[i] != '\0' && flag != 2; i++)
< 	{
< 		if (s[i] == '-')
< 			sign *= -1;
< 
< 		if (s[i] >= '0' && s[i] <= '9')
< 		{
< 			flag = 1;
< 			result *= 10;
< 			result += (s[i] - '0');
< 		}
< 		else if (flag == 1)
< 			flag = 2;
< 	}
< 
< 	if (sign == -1)
< 		output = -result;
< 	else
< 		output = result;
< 
< 	return (output);
< }
---
> #include "shell.h"
> //the task number 0
> /**
>  * is_interactive - return true if shell is intercative mode
>  * @info:parameter address
>  * Return:1 if interactive mode, else 0
>  */
> int is_interactive(info_t *info)
> {
> 	return (isatty(STDIN_FILENO) && info->readfd <= 2);
> }
> /**
>  * is_delimeter - checks if character is delimeter
>  * @c:the character to check
>  * @delimeter:delimeter string
>  * Return:1 if true, 0 if false
>  */
> int is_delimeter(char c, char *delimeter)
> {
> 	while (*delimeter)
> 		if (*delimeter++ == c)
> 			return (1);
> 	return (0);
> }
> /**
>  * is_alpha - checks alphabetic character
>  * @c: the character to input
>  * Return:1 if cis an alphabetic character, else 0
>  */
> int is_alpha(int c)
> {
> 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
> 		return (1);
> 	else
> 		return (0);
> }
> /**
>  * bet_check - converts string to integer
>  * @str:the string to be converted.
>  *
>  * Return:0 if no numbers in a string, convert number otherwise
>  */
> int bet_check(char *str)
> {
> 	int i, sign = 1, flag = 0, output;
> 	unsigned int result = 0;
> 
> 	for (i = 0; str[i] != '\0' && flag != 2; i++)
> 	{
> 		if (str[i] == '-')
> 			sign *= -1;
> 
> 		if (str[i] >= '0' && str[i] <= '9')
> 		{
> 			flag = 1;
> 			result *= 10;
> 			result += (str[i] - '0');
> 		}
> 		else if (flag == 1)
> 			flag = 2;
> 	}
> 	if (sign == -1)
> 		output = -result;
> 	else
> 		output = result;
> 	return (output);
> 
> }
> 
> 
> 
