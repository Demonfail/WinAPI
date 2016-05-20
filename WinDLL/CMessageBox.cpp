#include "CMessageBox.h"

ErrorCode CMessageBox::Show(string caption, string text, uint type) {
	m_iResult = MessageBox(NULL, TEXT(text), TEXT(caption), type);
	if (!m_iResult) {
		return ErrorCode::ERR_FAIL;
	}
	return ErrorCode::ERR_OK;
}

uint CMessageBox::Result() {
	return m_iResult;
}