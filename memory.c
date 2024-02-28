#include "main.h"
/**
 * _allocates - functio that allocate memory for an array using malloc
 * @bfree:array
 * @size:size
 * Return:pointer or NULL
 */
void *_allocates(unsigned int bfree, unsigned int size)
{
	unsigned int index = 0;
	char *ptr = NULL;

	if (bfree == 0 || size == 0)
		return (NULL);

	ptr = malloc(bfree * size);

	if (ptr == NULL)
		return (NULL);

	for(index < (bfree * size); index++)
		ptr[index] = 0;

	return (ptr);
}

