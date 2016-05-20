#pragma once

#include <Windows.h>
#include <Commctrl.h>

#include "CWindow.h"
#include "Error.h"
#include "Type.h"

class CProgressBar {
public:
	ErrorCode SetRange(uint min, uint max);
	ErrorCode SetStep(uint step);
	ErrorCode SetWindow(CWindow* window);

	ErrorCode SetPosition(uint x, uint y);
	ErrorCode SetSize(uint width, uint height);
	ErrorCode SetStyle(uint style);
	ErrorCode SetColour(uint colour);

	ErrorCode Create();
	ErrorCode Update();
	ErrorCode Destroy();

	ErrorCode EnableMarquee(uint state, uint time);
private:
	HWND m_hWindow;
	HWND m_hwProgressBar;

	uint m_iMin;
	uint m_iMax;
	uint m_iStep;

	uint m_iX;
	uint m_iY;
	uint m_iWidth;
	uint m_iHeight;

	uint m_iStyle;
};