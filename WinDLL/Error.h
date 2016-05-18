#pragma once

#include <iostream>
#include <Windows.h>
enum ErrorCode {
	ERR_OK       = -0x0000,
	ERR_FAIL     = -0x0001,
	ERR_LOAD     = -0x0002,
	ERR_REGISTER = -0x0003,
	ERR_CREATE   = -0x0004,
	ERR_HOOK     = -0x0005,
	ERR_SET      = -0x0006
};


const char* ErrorGetString(ErrorCode err);
void ErrorHandle(ErrorCode err);