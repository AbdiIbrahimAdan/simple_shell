#include "shell.h"

/**
 * input_buffer - buffers chained commands
 * @info:parameter struct
 * @buffer:address of the buffer
 * @len:address of length variables
 * Return:bytes read
 */
 ssize_t input_buffer(info_t *info, char **buffer, size_t *len)
{
	ssize_t read_bytes = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		read_bytes = getline(buffer, &len_p, stdin);
#else
		read_bytes = _getline(info, buffer, &len_p);
#endif
		if (read_bytes > 0)
		{
			if ((*buffer)[read_bytes - 1] == '\n')
			{
				(*buffer)[read_bytes - 1] = '\0';
				read_bytes++;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			/* if (_strchr(*buffer, ';')) command chain */
			{
				*len = read_bytes;
				info->cmd_buffer = buffer;
			}
		}
	}
	return (read_bytes);
}
/**
 * get_input - gets line minus newline
 * @info:parameter struct
 * Return:bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	ssize_t read_bytes = 0;
	char **buffer_p = &(info->arg), *p;

	_putchar(BUFFER_FLUSH);
	read_bytes = input_buffer(info, &buffer, &len);
	if (read_bytes == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buffer + i;

		check_chain(info, buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buffer, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buffer_type = CMD_NORM;
		}
		*buffer_p = p;
		return (_strlen(p));
	}
	*buffer_p = buffer;
	return (read_bytes);
}
/**
 * read_buffer - read the buffer
 * @info:parameter struct
 * @buffer:buffer
 * @i:size
 * Return:read bytes
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *i)
{
ssize_t read_bytes = 0;

if (*i)
	return (0);
read_bytes = read(info->readfd, buffer, READ_BUFFER_SIZE);
if (read_bytes >= 0)
	*i = read_bytes;
return (read_bytes);
}
/**
 * _getline - gets the next line of input  from STDIN
 * @info:parameter struct
 * @ptr:address of pointer to buffer, preallocated or NULL
 * @length:size of preallocated ptr buffer if it is not NULL
 * Return:s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUFFER_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t read_bytes = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;
	read_bytes = read_buffer(info, buffer, &len);
	if (read_bytes == -1 || (read_bytes == 0 && len == 0))
		return (-1);
	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int )(c - buffer) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buffer + i, k - i);
	else
		strncpy(new_p, buffer + i, k - i + 1);

	s += k -i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
/**
 * sigintHndler - blocks control plus c (ctrl -c)
 * @sig_num:the signal number
 * Return:void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts ("\n");
	_puts("$");
	_putchar(BUFFER_FLUSH);
}

