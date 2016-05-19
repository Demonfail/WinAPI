#include "CNotification.h"

CNotification::CNotification() {
	memset(&m_niTray, 0, sizeof(NOTIFYICONDATA));
	m_niTray.cbSize = sizeof(NOTIFYICONDATA);
	m_niTray.uVersion = NOTIFYICON_VERSION_4;
	m_niTray.uCallbackMessage = WM_TRAY;
}

ErrorCode CNotification::SetWindow(CWindow* window) {
	m_niTray.hWnd = window->GetWindowHandle();
	if (!m_niTray.hWnd) {
		return ErrorCode::ERR_SET;  
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetID(uint id) {
	m_niTray.uID = id;
	if (!m_niTray.uID) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetFlags(uint flags) {
	m_niTray.uFlags = flags;
	if (!m_niTray.uFlags) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetInfoFlags(uint flags) {
	m_niTray.dwInfoFlags = flags;
	if (!m_niTray.dwInfoFlags) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetTimeout(uint ms) {
	m_niTray.uTimeout = ms;
	if (!m_niTray.uTimeout) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetIcon(Icon* icon) {
	m_niTray.hIcon = icon->Get(IconType::IconBig);
	if (!m_niTray.hIcon) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::SetName(string name) {
	strcpy_s(m_niTray.szTip, TEXT(name));
	if (!m_niTray.szTip) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::Create() {
	Shell_NotifyIcon(NIM_SETVERSION, &m_niTray);
	if (!Shell_NotifyIcon(NIM_ADD, &m_niTray)) {
		return ErrorCode::ERR_CREATE;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::Update(string title, string tip) {
	strcpy_s(m_niTray.szInfoTitle, TEXT(title));
	strcpy_s(m_niTray.szInfo, TEXT(tip));
	if (!Shell_NotifyIcon(NIM_MODIFY, &m_niTray)) {
		return ErrorCode::ERR_FAIL;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CNotification::Destroy() {
	if (!Shell_NotifyIcon(NIM_DELETE, &m_niTray)) {
		return ErrorCode::ERR_FAIL;
	}
	return ErrorCode::ERR_OK;
}