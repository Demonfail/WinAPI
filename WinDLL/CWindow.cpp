#include "CWindow.h"

LONG_PTR g_lpWndProc = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
		case WM_DESTROY:
			DestroyWindow(hWnd);
			break;

		case WM_PAINT:
			ValidateRect(hWnd, 0);
			break;

		case WM_DROPFILES:
				MessageBox(hWnd, "That's what I'm talking about, yo.", "Hey hey hey.", 0);
			break;

		default:
			return CallWindowProc((WNDPROC)g_lpWndProc, hWnd, message, wParam, lParam);
			break;
	}

	return 0;
}

CWindow::CWindow() {
	m_wcClass.cbSize        = sizeof(WNDCLASSEX);
	m_wcClass.cbClsExtra    = 0;
	m_wcClass.cbWndExtra    = 0;
	m_wcClass.lpfnWndProc   = WndProc;
	m_wcClass.hInstance     = m_hiInst;
	m_wcClass.lpszClassName = m_sWinClassName;
	m_wcClass.lpszMenuName  = NULL;
}

ErrorCode CWindow::SetClassStyle(uint flags) {
	m_wcClass.style = flags;
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetIconFile(string file, uint size) {
	m_hiIcon = (HICON)LoadImage(m_hiInst, TEXT(file), IMAGE_ICON, size, size, LR_LOADFROMFILE);
	if (m_hiIcon == NULL) {
		return ErrorCode::ERR_LOAD;
	}
	m_wcClass.hIcon = m_hiIcon;
	m_wcClass.hIconSm = m_hiIcon;

	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetIconInternal(uint icon) {
	m_hiIcon = LoadIcon(m_hiInst, MAKEINTRESOURCE(icon));
	if (m_hiIcon == NULL) {
		return ErrorCode::ERR_LOAD;
	}
	m_wcClass.hIcon = m_hiIcon;
	m_wcClass.hIconSm = m_hiIcon;

	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetCursor(uint cursor) {
	LPCSTR Icons[6] = { IDC_ARROW, IDC_CROSS, IDC_HAND, IDC_HELP, IDC_NO };
	m_wcClass.hCursor = LoadCursor(m_hiInst, Icons[cursor]);
	if (m_wcClass.hCursor == NULL) {
		return ErrorCode::ERR_LOAD;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetBackground(uint background) {
	m_wcClass.hbrBackground = (HBRUSH)background;
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetPosition(uint x, uint y) {
	if (m_whHandle == NULL) {
		m_iWinX = x;
		m_iWinY = y;
		return ErrorCode::ERR_OK;
	}
	m_iWinX = x;
	m_iWinY = y;
	SetWindowPos(m_whHandle, NULL, x, y, m_iWinWidth, m_iWinHeight, NULL);
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetSize(uint width, uint height) {
	if (m_whHandle == NULL) {
		m_iWinWidth = width;
		m_iWinHeight = height;
		return ErrorCode::ERR_OK;
	}
	m_iWinWidth = width;
	m_iWinHeight = height;
	SetWindowPos(m_whHandle, NULL, m_iWinX, m_iWinY, width, height, NULL);
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetTitle(string title) {
	m_sWinTitle = title;
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetWindowStyle(uint flags) {
	m_iWinStyle = flags;
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetParent(CWindow* parent) {
	m_whParent = parent->GetWindowHandle();
	if (!m_lpWndProc) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::Set(HWND handle) {
	bool m_bIsMain = true;
	m_whHandle = handle;

	g_lpWndProc = SetWindowLongPtr(m_whHandle, GWL_WNDPROC, (LONG_PTR)WndProc);
	if (!g_lpWndProc) {
		return ErrorCode::ERR_HOOK;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::Create() {
	if (!RegisterClassEx(&m_wcClass)) {
		return ErrorCode::ERR_REGISTER;
	}

	m_whHandle = CreateWindow(m_sWinClassName, m_sWinTitle, m_iWinStyle, m_iWinX, m_iWinY, m_iWinWidth, m_iWinHeight, m_whParent, NULL, m_hiInst, NULL);
	if (!m_whHandle) {
		return ErrorCode::ERR_CREATE;
	}
	return ErrorCode::ERR_OK;
}

HWND CWindow::GetWindowHandle() {
	return m_whHandle;
}

ErrorCode CWindow::Update() {
	UpdateWindow(m_whHandle);
	ShowWindow(m_whHandle, true);

	MSG msg;
	GetMessage(&msg, NULL, 0, 0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	return ErrorCode::ERR_OK;
}