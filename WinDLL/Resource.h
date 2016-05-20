#pragma once

#include <Windows.h>
#include "Error.h"
#include "Type.h"

enum IconType {
	IconBig,
	IconSmall
};

enum ImageType {
	Bitmap
};

enum CursorType {
	CursorStatic
};

class Icon {
public:
	ErrorCode Load(string file);
	ErrorCode Free();

	HICON     Get(IconType icon);

private:
	HICON m_hiIconSmall;
	HICON m_hiIconBig;
};