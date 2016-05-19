#pragma once

#include <Windows.h>
#include "Error.h"
#include "Type.h"

class CConsole {
public:
	ErrorCode Print(string msg);
	ErrorCode Create();
	ErrorCode Update();
	ErrorCode Destroy();
private:

};