#pragma once

#include <Windows.h>
#include "Error.h"
#include "Type.h"

class CConsole {
public:
	ErrorCode Output(string tag, string text);
	ErrorCode Create();
	ErrorCode Destroy();
private:
	bool m_bExist;
	FILE* m_pCout;
};
