global.__WINAPI_DLL__ = "WinDLL.dll";

//Windows.
global.__WINAPI__[0]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowAdd", dll_cdecl, ty_real, 0);
global.__WINAPI__[1]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowCreate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[2]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowUpdate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[3]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetSize", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[4]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetPosition", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[5]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetClassStyle", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[6]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetIcon", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[7]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetCursor", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[8]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetBackground", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[9]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetTitle", dll_cdecl, ty_real, 2, ty_real, ty_string);
global.__WINAPI__[10] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetParent", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[11] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetStyle", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[12] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSet", dll_cdecl, ty_real, 2, ty_real, ty_string);
global.__WINAPI__[13] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetFlag", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

//Resources.
global.__WINAPI__[20] = external_define(global.__WINAPI_DLL__, "WinAPI_ResourceIconLoad", dll_cdecl, ty_real, 1, ty_string);

//Taskbar
global.__WINAPI__[30] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarAdd", dll_cdecl, ty_real, 0);
global.__WINAPI__[31] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetWindow", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[32] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetID", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[33] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetFlags", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[34] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetInfoFlags", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[35] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetTimeout", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[36] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetIcon", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[37] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarSetName", dll_cdecl, ty_real, 2, ty_real, ty_string);
global.__WINAPI__[38] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarCreate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[39] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarUpdate", dll_cdecl, ty_real, 3, ty_real, ty_string, ty_string);
global.__WINAPI__[40] = external_define(global.__WINAPI_DLL__, "WinAPI_TaskbarDestroy", dll_cdecl, ty_real, 1, ty_real);

//Console.
global.__WINAPI__[41] = external_define(global.__WINAPI_DLL__, "WinAPI_ConsoleAdd", dll_cdecl, ty_real, 0);
global.__WINAPI__[42] = external_define(global.__WINAPI_DLL__, "WinAPI_ConsoleCreate", dll_cdecl, ty_real, 0);
global.__WINAPI__[43] = external_define(global.__WINAPI_DLL__, "WinAPI_ConsoleDestroy", dll_cdecl, ty_real, 0);
global.__WINAPI__[44] = external_define(global.__WINAPI_DLL__, "WinAPI_ConsoleOutput", dll_cdecl, ty_real, 1, ty_string);

//Dialogs.
global.__WINAPI__[50] = external_define(global.__WINAPI_DLL__, "WinAPI_MessageShow", dll_cdecl, ty_real, 3, ty_string, ty_string, ty_real);

//Progress Bar
global.__WINAPI__[70] = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarAdd", dll_cdecl, ty_real, 0);
global.__WINAPI__[71]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetRange", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[72]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetStep", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[73]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetWindow", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[74]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarCreate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[75]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarUpdate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[76]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarDestroy", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[77]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetPosition", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[78]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetSize", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[79]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarSetStyle", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[80]  = external_define(global.__WINAPI_DLL__, "WinAPI_ProgressBarEnableMarquee", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
