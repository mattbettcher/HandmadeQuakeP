// Types are included in their own header.
#include "quakedef.h"


i32 main(i32 argc, char **argv)
{
	// This is the equivalent of all the parsing from WinMain.
	COM_ParseCmdLine(argc, argv);

	i32 test = Com_CheckParm("-hello");
	i32 test2 = Com_CheckParm("-alpha");
	i32 num = Q_atoi(com_argv[3]);

	return 0;
}