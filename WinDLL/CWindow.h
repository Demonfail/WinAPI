#pragma once

#include <Windows.h>
#include <Commctrl.h>

#include "Resource.h"
#include "Error.h"
#include "Type.h"

enum CWindowFlags {
	flg_ShowWindow,
	flg_DragFiles
};

class CWindow {
public:
	CWindow();
	ErrorCode SetSize(uint width, uint height);
	ErrorCode SetPosition(uint x, uint y);
	ErrorCode SetClassStyle(uint flags);
	ErrorCode SetIcon(Icon* icon);
	ErrorCode SetCursor(uint cursor);
	ErrorCode SetBackground(uint background);
	ErrorCode SetTitle(string title);
	ErrorCode SetParent(CWindow* parent);
	ErrorCode SetWindowStyle(uint flags);
	ErrorCode SetWindowFlag(CWindowFlags flag, uint state);
	ErrorCode Create();
	ErrorCode Update();

	ErrorCode Set(HWND handle);

	HWND GetWindowHandle();

private:
	HICON          m_hiIcon;
	HCURSOR    m_hcCursor = NULL;
	HWND       m_whHandle = NULL;
	HINSTANCE  m_hiInst;
	WNDCLASSEX m_wcClass;
	LONG_PTR   m_lpWndProc = NULL;

	uint   m_iWinStyle;
	uint   m_iWinX = CW_USEDEFAULT;
	uint   m_iWinY = CW_USEDEFAULT;
	uint   m_iWinWidth;
	uint   m_iWinHeight;
	HWND   m_whParent = NULL;
	string m_sWinTitle;
	string m_sWinClassName = "gmapi_window333";

	bool m_bIsMain;
};