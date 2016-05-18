global.__WINAPI_DLL__ = "WinDLL.dll";

//Windows.
global.__WINAPI__[0]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowAdd", dll_cdecl, ty_real, 0);
global.__WINAPI__[1]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowCreate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[2]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowUpdate", dll_cdecl, ty_real, 1, ty_real);
global.__WINAPI__[3]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetSize", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[4]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetPosition", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__WINAPI__[5]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetClassStyle", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[6]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetIconFile", dll_cdecl, ty_real, 3, ty_real, ty_string, ty_real);
global.__WINAPI__[7]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetIconInternal", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[8]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetCursor", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[9]  = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetBackground", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[10] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetTitle", dll_cdecl, ty_real, 2, ty_real, ty_string);
global.__WINAPI__[11] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetParent", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[12] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSetStyle", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.__WINAPI__[13] = external_define(global.__WINAPI_DLL__, "WinAPI_WindowSet", dll_cdecl, ty_real, 2, ty_real, ty_string);