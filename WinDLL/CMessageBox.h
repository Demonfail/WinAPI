#pragma once

#include <Windows.h>
#include "Error.h"
#include "Type.h"

class CMessageBox {
public:
	ErrorCode Show(string caption, string text, uint type);
	uint      Result();

private:
	uint m_iResult;
};