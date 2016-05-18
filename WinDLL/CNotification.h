#pragma once

#include <Windows.h>
#include "CWindow.h"
#include "Resource.h"
#include "Error.h"
#include "Type.h"

#define WM_TRAY (WM_USER+1)

class CNotification {
public:
	CNotification();
	ErrorCode SetWindow(CWindow* window);
	ErrorCode SetID(uint id);
	ErrorCode SetFlags(uint flags);
	ErrorCode SetInfoFlags(uint flags);
	ErrorCode SetTimeout(uint ms);
	ErrorCode SetIcon(Icon* icon);
	ErrorCode SetName(string name);

	ErrorCode Create();
	ErrorCode Update(string title, string tip);
	ErrorCode Destroy();

private:
	NOTIFYICONDATA m_niTray;
	HICON          m_hiIcon;
};