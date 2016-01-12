/*
*	
*
*	This file separates all the platform specific 'main' entry points and preps to call q_main(i32 argc, u8* argv[])
*/

#include "types.h"

#ifdef WIN32
#include <Windows.h>
#endif

extern i32 argc;
extern u8 **argv;
i32 q_main();

// WinMain for windows
#ifdef WIN32

#define MAX_WIN32_ARGS 50
u8* argv_win32[MAX_WIN32_ARGS];
i32 argc_win32;

// To handle WinMain we parse the lpCmdLine into separate strings
// This is handled automagically on most other OS's
i32 CALLBACK WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, i32 nCmdShow)
{
	argv_win32[0] = "";

	while (*lpCmdLine && (argc_win32 < MAX_WIN32_ARGS + 1))
	{
		while (*lpCmdLine && ((*lpCmdLine <= 32) || (*lpCmdLine > 126)))
			lpCmdLine++;

		if (*lpCmdLine)
		{
			argv_win32[argc_win32] = lpCmdLine;
			argc_win32++;

			while (*lpCmdLine && ((*lpCmdLine > 32) && (*lpCmdLine <= 126)))
				lpCmdLine++;

			if (*lpCmdLine)
			{
				*lpCmdLine = 0;
				lpCmdLine++;
			}
		}
	}

	argc = argc_win32;
	argv = argv_win32;

	return q_main();
}

// TODO(matt) need to make sure that the first arg is always the same on all systems.
// TODO(matt) when running non WinMain on Windows the first arg in the full path?
#elif MACOSX || LINUX

// Almost all other OS's start with a set number of args in standard C string format.
i32 main(i32 argc, u8* argv[])
{
	q_main();
}

#endif