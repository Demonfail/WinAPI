#include "CProgressBar.h"

ErrorCode CProgressBar::Create() {
	INITCOMMONCONTROLSEX con;
	con.dwSize = sizeof(INITCOMMONCONTROLSEX);
	con.dwICC = ICC_PROGRESS_CLASS;

	if (!InitCommonControlsEx(&con)) {
		return ErrorCode::ERR_REGISTER;
	}

	m_hwProgressBar = CreateWindowEx(NULL, PROGRESS_CLASS, (LPTSTR)NULL, m_iStyle, m_iX, m_iY, m_iWidth, m_iHeight, m_hWindow, (HMENU)0, GetModuleHandle(NULL), NULL);
	if (!m_hwProgressBar) {
		return ErrorCode::ERR_CREATE;
	}

	SendMessage(m_hwProgressBar, PBM_SETRANGE, 0, MAKELPARAM(m_iMin, m_iMax));
	SendMessage(m_hwProgressBar, PBM_SETSTEP,  (WPARAM)m_iStep, 0);
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::EnableMarquee(uint state, uint time) {
	SendMessage(m_hwProgressBar, PBM_SETMARQUEE, state, time);
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::Update() {
	SendMessage(m_hwProgressBar, PBM_STEPIT, 0, 0);
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::Destroy() {
	DestroyWindow(m_hwProgressBar);
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetWindow(CWindow* window) {
	m_hWindow = window->GetWindowHandle();
	if (!m_hWindow) {
		return ErrorCode::ERR_SET;
	}
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetRange(uint min, uint max) {
	m_iMin = min;
	m_iMax = max;
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetStep(uint step) {
	m_iStep = step;
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetSize(uint width, uint height) {
	m_iWidth = width;
	m_iHeight = height;
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetPosition(uint x, uint y) {
	m_iX = x;
	m_iY = y;
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetColour(uint colour) {
	/**
	 * STUB.
	**/
	return ErrorCode::ERR_OK;
}

ErrorCode CProgressBar::SetStyle(uint style) {
	m_iStyle = style;
	return ErrorCode::ERR_OK;
}