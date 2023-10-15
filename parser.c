#include "shell.h"
/**
 * is_command - determines if file is an executable command
 * @info:info struct
 * @path:path to the file
 * Return:1 if true, 0 otherwise
 */
int is_command(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * duplicates_chars- duplicates characters
 * @pathstr:PATH string
 * @start:starting index
 * @stop:stopping index
 * Return:pointer to new buffer
 */
char *duplicates_chars(char *pathstr, int start, int stop)
{
	static char buffer[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buffer[k++] = pathstr[i];
	buffer[k] = 0;
	return (buffer);
}
/**
 * find_path_string - finds this cmd in the path string
 * @info:info struct
 * @pathstr:PATH string
 * @cmd:find cmd
 * Return:full path of cmd if found or NULL.
 */
char *find_path_string(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;
/* cmd mean command */
	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_command(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = duplicates_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

