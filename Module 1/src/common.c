#include "quakedef.h"

i32 com_argc;
char **com_argv;

void COM_ParseCmdLine(i32 argc, char **argv)
{
	// because we are using the just main we don't have to do any crazy parsing here.
	com_argc = argc;
	com_argv = argv;
}

i32 Com_CheckParm(char *param)
{
	for (i32 i = 1; i < com_argc; i++)
	{
		if (!Q_strcmp(param, com_argv[i]))
			return i;
	}
	return 0;
}