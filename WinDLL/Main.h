#pragma once

#include <vector>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <Commctrl.h>
#include <Lmcons.h>
#include <assert.h>
#include <string>

#include "CConsole.h"
#include "CWindow.h"
#include "CNotification.h"
#include "CProgressBar.h"
#include "CMessageBox.h"

#include "Resource.h"
#include "Error.h"
#include "Type.h"

#define GMEXPORT extern "C" __declspec (dllexport)

class WinAPI {
public:
	std::vector<Icon*> m_vIcon;

	std::vector<CWindow*> m_vWindow;
	std::vector<CNotification*> m_vNotification;
	std::vector<CProgressBar*> m_vProgressBar;

	CConsole* m_pConsole = new CConsole();

	LPDIRECT3DDEVICE9 m_pD3Ddev;
};