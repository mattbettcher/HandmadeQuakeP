#pragma once

extern i32 com_argc;
extern char **com_argv;

void COM_ParseCmdLine(i32 argc, char **argv);
i32 Com_CheckParm(char *param);