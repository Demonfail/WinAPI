#include "CWindow.h"

std::vector<std::string> g_vDraggedFiles;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
		case WM_DESTROY:
				DestroyWindow(hWnd);
			break;

		case WM_PAINT:
				ValidateRect(hWnd, NULL);
			break;

		case WM_DROPFILES: {
			HDROP hDrop = (HDROP)wParam;
			uint oldsize = g_vDraggedFiles.size();
			g_vDraggedFiles.resize(oldsize + DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0));

			for (uint i = oldsize; i < g_vDraggedFiles.size(); ++i) {
				g_vDraggedFiles[i].resize(DragQueryFile(hDrop, i - oldsize, NULL, 0) + 1);
				DragQueryFile(hDrop, i - oldsize, (char*)g_vDraggedFiles[i].c_str(), g_vDraggedFiles[i].size());
			}
			DragFinish(hDrop);
		}
		break;

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
			break;
	}
	return 0;
}

LRESULT CALLBACK WndSubclass(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData) {
	switch (msg) {
		case WM_DROPFILES: {
			HDROP hDrop = (HDROP)wParam;
			uint oldsize = g_vDraggedFiles.size();
			g_vDraggedFiles.resize(oldsize + DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0));

			for (uint i = oldsize; i < g_vDraggedFiles.size(); ++i) {
				g_vDraggedFiles[i].resize(DragQueryFile(hDrop, i - oldsize, NULL, 0) + 1);
				DragQueryFile(hDrop, i - oldsize, (char*)g_vDraggedFiles[i].c_str(), g_vDraggedFiles[i].size());
			}
			DragFinish(hDrop);
		}
		break;

		default:
			return DefSubclassProc(hWnd, msg, wParam, lParam);
			break;
	}
	return 0;
}


CWindow::CWindow() {
	m_hiInst = GetModuleHandle(NULL);
	memset(&m_wcClass, 0, sizeof(WNDCLASSEX));

	m_wcClass.cbSize        = sizeof(WNDCLASSEX);
	m_wcClass.cbClsExtra    = 0;
	m_wcClass.cbWndExtra    = 0;
	m_wcClass.lpfnWndProc   = WndProc;
	m_wcClass.hInstance     = m_hiInst;
	m_wcClass.lpszClassName = m_sWinClassName;
	m_wcClass.lpszMenuName  = NULL;
}

uint CWindow::GetDraggedFileCount() {
	return g_vDraggedFiles.size();
}

string CWindow::GetDraggedFile(uint index) {
	return g_vDraggedFiles[index].c_str();
}

ErrorCode CWindow::ClearDraggedFiles() {
	g_vDraggedFiles.clear();
	g_vDraggedFiles.resize(0);
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetClassStyle(uint flags) {
	m_wcClass.style = flags;
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::SetIcon(Icon* icon) {
	m_wcClass.hIcon = icon->Get(IconType::IconBig);
	if (!m_wcClass.hIcon) {
		return ErrorCode::ERR_SET;
	}
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

ErrorCode CWindow::SetWindowFlag(CWindowFlags flag, uint state) {
	switch (flag) {
		case CWindowFlags::flg_ShowWindow: {
			int States[5] = { SW_MINIMIZE, SW_MAXIMIZE, SW_RESTORE, SW_SHOW, SW_HIDE };
			ShowWindow(m_whHandle, States[state]);
			return ErrorCode::ERR_OK;
		} break;

		case CWindowFlags::flg_DragFiles: {
			bool States[2] = { false, true };
			DragAcceptFiles(m_whHandle, States[state]);
			return ErrorCode::ERR_OK;
		} break;

		default: {
			return ErrorCode::ERR_FAIL;
		} break;
	}
	return ErrorCode::ERR_FAIL;
}

ErrorCode CWindow::SetParent(CWindow* parent) {
	m_whParent = parent->GetWindowHandle();
	if (!m_whParent) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CWindow::Set(HWND handle) {
	bool m_bIsMain = true;
	m_whHandle = handle;

	if (!SetWindowSubclass(m_whHandle, WndSubclass, 0, 0)) {
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
	while (1) {
		UpdateWindow(m_whHandle);

		MSG msg;
		GetMessage(&msg, m_whHandle, 0, 0);
		PeekMessage(&msg, m_whHandle, 0, 0, NULL);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		return ErrorCode::ERR_OK;
	}
}