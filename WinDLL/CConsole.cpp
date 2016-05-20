#include "CConsole.h"

ErrorCode CConsole::Output(string tag, string text) {
	if (!m_bExist) {
		return ErrorCode::ERR_FAIL;
	}
	std::cout << tag << text << std::endl;
	return ErrorCode::ERR_OK;
}

ErrorCode CConsole::Create() {
	if (!AllocConsole()) {
		return ErrorCode::ERR_FAIL;
	}
	freopen_s(&m_pCout, "CONOUT$", "wt", stdout); //returns 0
	SetConsoleTitle("Debug Console");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	m_bExist = true;

	return ErrorCode::ERR_OK;
}

ErrorCode CConsole::Destroy() {
	if (!FreeConsole()) {
		return ErrorCode::ERR_FAIL;
	}
	fclose(m_pCout);
	m_bExist = false;
	return ErrorCode::ERR_OK;
}