#include "Main.h"

/**
#* Window.
**/
GMEXPORT double WinAPI_WindowAdd() {
	Window.push_back(new CWindow());
	return Window.size() - 1;
}

GMEXPORT double WinAPI_WindowSetSize(double index, double width, double height) {
	ErrorCode err = Window[(uint)index]->SetSize((uint)width, (uint)height);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetPosition(double index, double x, double y) {
	ErrorCode err = Window[(uint)index]->SetPosition((uint)x, (uint)y);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetClassStyle(double index, double style) {
	ErrorCode err = Window[(uint)index]->SetClassStyle((uint)style);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetIconFile(double index, string icon, double size) {
	ErrorCode err = Window[(uint)index]->SetIconFile(icon, (uint)size);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetIconInternal(double index, double icon) {
	ErrorCode err = Window[(uint)index]->SetIconInternal((uint)icon);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetCursor(double index, double cursor) {
	ErrorCode err = Window[(uint)index]->SetCursor((uint)cursor);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetBackground(double index, double colour) {
	ErrorCode err = Window[(uint)index]->SetBackground((uint)colour);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetTitle(double index, string title) {
	ErrorCode err = Window[(uint)index]->SetTitle(title);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetParent(double index, double index2) {
	ErrorCode err = Window[(uint)index]->SetParent(Window[(uint)index2]);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSetStyle(double index, double style) {
	ErrorCode err = Window[(uint)index]->SetWindowStyle((uint)style);
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowCreate(double index) {
	ErrorCode err = Window[(uint)index]->Create();
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowUpdate(double index) {
	ErrorCode err = Window[(uint)index]->Update();
	ErrorHandle(err);
	return 1;
}

GMEXPORT double WinAPI_WindowSet(double index, LPCSTR WinH) {
	ErrorCode err = Window[(uint)index]->Set((HWND)WinH);
	ErrorHandle(err);
	return 1;
}
/*
#define ID_TRAY_APP_ICON    1001
#define ID_TRAY_EXIT        1002
#define WM_TRAY_ICON          (WM_USER + 1)

HWND WindowHandle = NULL;
LONG_PTR OldWndProc = NULL;
LPCTSTR WinTitle = "";
NOTIFYICONDATA IconData;
HICON WinIcon = NULL;
std::vector<std::string> draggedFiles;

GMEXPORT double Win_Init(int WinH, const char* title, const char* Icon) {
	WindowHandle = (HWND)(int)WinH;
	WinTitle = TEXT(title);
	WinIcon = (HICON)LoadImage(NULL, TEXT(Icon), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
	return 1;
}

GMEXPORT double Win_DragFileEnable(double enable) {
	bool TypeList[2] = { false, true };
	DragAcceptFiles(WindowHandle, TypeList[(int)enable]);
	return 1;
}

GMEXPORT double Win_DragFileCount() {
	return draggedFiles.size();
}

GMEXPORT const char* Win_DragFileGet(double index) {
	return draggedFiles[(int)index].c_str();
}

GMEXPORT double Win_DragFileClear() {
	draggedFiles.clear();
	return 1;
}

GMEXPORT double Win_TrayCreateIcon(const char* Tip) {
	memset(&IconData, 0, sizeof(NOTIFYICONDATA));
	IconData.cbSize = sizeof(NOTIFYICONDATA);
	IconData.hWnd = WindowHandle;
	IconData.uID = ID_TRAY_APP_ICON;

	IconData.uVersion = NOTIFYICON_VERSION_4;
	IconData.uFlags = NIF_ICON | NIF_TIP | NIF_GUID | NIF_INFO;
	IconData.dwInfoFlags = 0 | NIIF_LARGE_ICON | NIIF_RESPECT_QUIET_TIME;
	IconData.uCallbackMessage = WM_TRAY_ICON;
	IconData.uTimeout = 2000;
	IconData.hIcon = WinIcon;
	strcpy_s(IconData.szTip, TEXT(Tip));
	return 1;
}

GMEXPORT double Win_TrayAddIcon() {
	Shell_NotifyIcon(NIM_ADD, &IconData);
	Shell_NotifyIcon(NIM_SETVERSION, &IconData);
	return 1;
}

GMEXPORT double Win_TrayNotification(const char* name, const char* text) {
	strcpy_s(IconData.szInfo, TEXT(text));
	strcpy_s(IconData.szInfoTitle, TEXT(name));
	Shell_NotifyIcon(NIM_MODIFY, &IconData);
	return 1;
}

GMEXPORT double Win_TrayRemoveIcon() {
	Shell_NotifyIcon(NIM_DELETE, &IconData);
	return 1;
}

GMEXPORT double Win_MessageBox(double type, const char* text) {
	UINT TypeList[4] = { MB_ICONEXCLAMATION, MB_ICONINFORMATION, MB_ICONQUESTION, MB_ICONSTOP };
	MessageBox(WindowHandle, TEXT(text), WinTitle, MB_OK | TypeList[(int)type]);
	return 1;
}

GMEXPORT double Win_WindowHide() {
	ShowWindow(WindowHandle, SW_HIDE);
	return 1;
}

GMEXPORT double Win_WindowShow() {
	ShowWindow(WindowHandle, SW_SHOW);
	return 1;
}

GMEXPORT double Win_WindowSetIcon() {
	SendMessage(WindowHandle, WM_SETICON, ICON_SMALL, (LPARAM)WinIcon);
	SendMessage(WindowHandle, WM_SETICON, ICON_BIG, (LPARAM)WinIcon);
	SendMessage(GetWindow(WindowHandle, GW_OWNER), WM_SETICON, ICON_SMALL, (LPARAM)WinIcon);
	SendMessage(GetWindow(WindowHandle, GW_OWNER), WM_SETICON, ICON_BIG, (LPARAM)WinIcon);
	return 1;
}

GMEXPORT const char* Win_GetUsername() {
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	return username;
}
*/