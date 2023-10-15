#include "shell.h"
/**
 * memory_set - fills memory with a constant byte
 * @s:point to the memory area
 * @byte:byte fill *s
 * @num:the amount of bytes to be filled
 * Return:pointer to the memory area s
 */
char *memory_set(char *s, char byte, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		s[j] = byte;
	return (s);
}
/**
 * ffree - free a string of strings
 * @pp: string of string
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*PP++);
	free(a);
}
/**
 * _reallocate -reallocates block of memory
 * @ptr:pointer to previous mallocated block
 * @old_size:bytes size of previous block
 * @new_size:bytes size of new block
 * Return:pointer to the block of memory
 */
void _reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(news_size);
	if (!p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

