#include "shell.h"

/**
 * my_exit - exi the shell
 * @info:structure argument  used to maintain the constant function protope.
 * Return:exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int my_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /*exit argument*/
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, illegal number:);
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mydirectory - changes the current directory of the process
 * @info:structure conataining potential arguments.used to maintain 
 * constant function prototype.
 * Return:Always 0
 */
int _mydirectory(info_t, *info)
{
	char *str, *dir,buffer[1024];
	int chdir_retsult;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO:>>getcwd failure message  here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_result =
				chdir((dir = _getenv(info, "PWD=")) ? dir:"/");
		else
			chdir_result = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0);
	{

		if (!_getenv(info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPPWD=")), _putchar('\n);
		chdir_result = 
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_result = chdir(info->argv[1]);
	if (chdir_result == -1)
	{
		print_error(info, "can not change directory");
		_eputs(info->argv[1]), _eputchar("\n");
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes current directory of the process
 * @info:structure containing potential arguments
 * used to maintain, constant function prototype.
 * Return:Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works ,function not implemented\n");
	if (0)
		_puts(*arg_array);
	return(0);
}






