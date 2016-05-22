#include "Main.h"

WinAPI* winapi = new WinAPI();

//Resource
GMEXPORT double WinAPI_ResourceIconLoad(string file) {
	winapi->m_vIcon.push_back(new Icon());
	uint ind = winapi->m_vIcon.size() - 1;
	ErrorCode err = winapi->m_vIcon[ind]->Load(file);
	ErrorHandle(err);

	return ind;
}

GMEXPORT double WinAPI_ResourceIconFree(double index) {
	ErrorCode err = winapi->m_vIcon[(uint)index]->Free();
	return err;
}



//Console
GMEXPORT double WinAPI_ConsoleAdd() {
	winapi->m_pConsole = new CConsole();
	return ErrorCode::ERR_OK;
}

GMEXPORT double WinAPI_ConsoleCreate() {
	ErrorCode err = winapi->m_pConsole->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ConsoleDestroy() {
	ErrorCode err = winapi->m_pConsole->Destroy();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ConsoleOutput(string text) {
	ErrorCode err = winapi->m_pConsole->Output("", text);
	return ErrorHandle(err);
}



//Window
GMEXPORT double WinAPI_WindowAdd() {
	winapi->m_vWindow.push_back(new CWindow());
	return  winapi->m_vWindow.size() - 1;
}

GMEXPORT double WinAPI_WindowGetDragFileCount(double index) {
	uint cnt = winapi->m_vWindow[(uint)index]->GetDraggedFileCount();
	return (double) cnt;
}

GMEXPORT string WinAPI_WindowGetDragFile(double index, double fileindex) {
	return winapi->m_vWindow[(uint)index]->GetDraggedFile((uint)fileindex);
}

GMEXPORT double WinAPI_WindowClearDragFiles(double index) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->ClearDraggedFiles();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetSize(double index, double width, double height) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetSize((uint)width, (uint)height);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetPosition(double index, double x, double y) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetPosition((uint)x, (uint)y);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetClassStyle(double index, double style) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetClassStyle((uint)style);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetIcon(double index, double icon) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetIcon(winapi->m_vIcon[(uint)icon]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetCursor(double index, double cursor) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetCursor((uint)cursor);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetBackground(double index, double colour) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetBackground((uint)colour);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetTitle(double index, string title) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetTitle(title);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetParent(double index, double index2) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetParent(winapi->m_vWindow[(uint)index2]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetStyle(double index, double style) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetWindowStyle((uint)style);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSetFlag(double index, double flag, double state) {
	CWindowFlags flags[2] = { CWindowFlags::flg_ShowWindow, CWindowFlags::flg_DragFiles };
	ErrorCode err = winapi->m_vWindow[(uint)index]->SetWindowFlag(flags[(uint)flag], (uint)state);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowCreate(double index) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowUpdate(double index) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->Update();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_WindowSet(double index, LPCSTR WinH) {
	ErrorCode err = winapi->m_vWindow[(uint)index]->Set((HWND)WinH);
	return ErrorHandle(err);
}



//Taskbar
GMEXPORT double WinAPI_TaskbarAdd() {
	winapi->m_vNotification.push_back(new CNotification());
	return winapi->m_vNotification.size() - 1;
}

GMEXPORT double WinAPI_TaskbarSetWindow(double index, double window) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetWindow(winapi->m_vWindow[(uint)window]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetID(double index, double id) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetID((uint)id);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetFlags(double index, double flags) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetFlags((uint)flags);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetInfoFlags(double index, double flags) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetInfoFlags((uint)flags);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetTimeout(double index, double ms) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetTimeout((uint)ms);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetIcon(double index, double icon) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetIcon(winapi->m_vIcon[(uint)icon]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarSetName(double index, string name) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->SetName(name);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarCreate(double index) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarUpdate(double index, string title, string tip) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->Update(title, tip);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_TaskbarDestroy(double index) {
	ErrorCode err = winapi->m_vNotification[(uint)index]->Destroy();
	delete winapi->m_vNotification[(uint)index];
	return ErrorHandle(err);
}



//Progress Bar
GMEXPORT double WinAPI_ProgressBarAdd() {
	winapi->m_vProgressBar.push_back(new CProgressBar());

	return winapi->m_vProgressBar.size() - 1;
}

GMEXPORT double WinAPI_ProgressBarSetRange(double index, double min, double max) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetRange((uint)min, (uint)max);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarSetStep(double index, double step) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetStep((uint)step);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarSetPosition(double index, double x, double y) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetPosition((uint)x, (uint)y);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarSetSize(double index, double width, double height) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetSize((uint)width, (uint)height);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarSetStyle(double index, double style) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetStyle((uint)style);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarEnableMarquee(double index, double state, double time) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->EnableMarquee((uint)state, (uint)time);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarSetWindow(double index, double window) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->SetWindow(winapi->m_vWindow[(uint)window]);
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarCreate(double index) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->Create();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarUpdate(double index) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->Update();
	return ErrorHandle(err);
}

GMEXPORT double WinAPI_ProgressBarDestroy(double index) {
	ErrorCode err = winapi->m_vProgressBar[(uint)index]->Destroy();
	return ErrorHandle(err);
}


//Message Box
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


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:

		break;

		case DLL_THREAD_ATTACH:
		break;

		case DLL_THREAD_DETACH:
		break;

		case DLL_PROCESS_DETACH:
			delete winapi;
		break;
	} return TRUE;
}