#include "Main.h"



/**
#* Console.
**/
GMEXPORT double WinAPI_ConsoleAdd() {
	m_pConsole = new CConsole();
	return -0x0000;
}

GMEXPORT double WinAPI_ConsoleCreate() {
	ErrorCode err = m_pConsole->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ConsoleDestroy() {
	ErrorCode err = m_pConsole->Destroy();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ConsoleOutput(string text) {
	ErrorCode err = m_pConsole->Output("", text);
	return ErrorHandle(err);
}

/**
#* Message Box
*/
GMEXPORT double WinAPI_MessageShow(string caption, string text, double flags) {
	CMessageBox* msg = new CMessageBox();

	ErrorCode err = msg->Show(caption, text, (uint)flags);
	if (!ErrorHandle(err)) {
		return 0;
	}
	uint res = msg->Result();
	delete msg;

	return res;
}

/**
#* Resource.
**/
GMEXPORT double WinAPI_ResourceIconLoad(string file) {
	m_vIcon.push_back(new Icon());
	uint ind = m_vIcon.size() - 1;
	ErrorCode err = m_vIcon[ind]->Load(file);
	ErrorHandle(err);

	return ind;
}

GMEXPORT double WinAPI_ResourceIconFree(double index) {
	ErrorCode err = ErrorCode::ERR_OK;
	return err;
}
/**
#* Notification.
**/
GMEXPORT double WinAPI_TaskbarAdd() {
	m_vNotification.push_back(new CNotification());
	return m_vNotification.size() - 1;
}

GMEXPORT double WinAPI_TaskbarSetWindow(double index, double window) {
	ErrorCode err = m_vNotification[(uint)index]->SetWindow(m_vWindow[(uint)window]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetID(double index, double id) {
	ErrorCode err = m_vNotification[(uint)index]->SetID((uint)id);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetFlags(double index, double flags) {
	ErrorCode err = m_vNotification[(uint)index]->SetFlags((uint)flags);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetInfoFlags(double index, double flags) {
	ErrorCode err = m_vNotification[(uint)index]->SetInfoFlags((uint)flags);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetTimeout(double index, double ms) {
	ErrorCode err = m_vNotification[(uint)index]->SetTimeout((uint)ms);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetIcon(double index, double icon) {
	ErrorCode err = m_vNotification[(uint)index]->SetIcon(m_vIcon[(uint)icon]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetName(double index, string name) {
	ErrorCode err = m_vNotification[(uint)index]->SetName(name);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarCreate(double index) {
	ErrorCode err = m_vNotification[(uint)index]->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarUpdate(double index, string title, string tip) {
	ErrorCode err = m_vNotification[(uint)index]->Update(title, tip);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarDestroy(double index) {
	ErrorCode err = m_vNotification[(uint)index]->Destroy();
	delete m_vNotification[(uint)index];
	return ErrorHandle(err);
}

/**
#* Window.
**/
GMEXPORT double WinAPI_WindowAdd() {
	m_vWindow.push_back(new CWindow());
	return  m_vWindow.size() - 1;
}

GMEXPORT double WinAPI_WindowSetSize(double index, double width, double height) {
	ErrorCode err = m_vWindow[(uint)index]->SetSize((uint)width, (uint)height);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetPosition(double index, double x, double y) {
	ErrorCode err = m_vWindow[(uint)index]->SetPosition((uint)x, (uint)y);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetClassStyle(double index, double style) {
	ErrorCode err = m_vWindow[(uint)index]->SetClassStyle((uint)style);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetIconFile(double index, string icon, double size) {
	ErrorCode err = m_vWindow[(uint)index]->SetIconFile(icon, (uint)size);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetIconInternal(double index, double icon) {
	ErrorCode err = m_vWindow[(uint)index]->SetIconInternal((uint)icon);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetCursor(double index, double cursor) {
	ErrorCode err = m_vWindow[(uint)index]->SetCursor((uint)cursor);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetBackground(double index, double colour) {
	ErrorCode err = m_vWindow[(uint)index]->SetBackground((uint)colour);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetTitle(double index, string title) {
	ErrorCode err = m_vWindow[(uint)index]->SetTitle(title);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetParent(double index, double index2) {
	ErrorCode err = m_vWindow[(uint)index]->SetParent(m_vWindow[(uint)index2]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetStyle(double index, double style) {
	ErrorCode err = m_vWindow[(uint)index]->SetWindowStyle((uint)style);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetFlag(double index, double flag, double state) {
	CWindowFlags flags[2] = { CWindowFlags::flg_ShowWindow, CWindowFlags::flg_DragFiles };
	ErrorCode err = m_vWindow[(uint)index]->SetWindowFlag(flags[(uint)flag], (uint)state);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowCreate(double index) {
	ErrorCode err = m_vWindow[(uint)index]->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowUpdate(double index) {
	ErrorCode err = m_vWindow[(uint)index]->Update();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSet(double index, LPCSTR WinH) {
	ErrorCode err = m_vWindow[(uint)index]->Set((HWND)WinH);
	return ErrorHandle(err);
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