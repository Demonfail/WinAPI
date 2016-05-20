#pragma once

#include <vector>
#include <Windows.h>
#include <Commctrl.h>
#include <Lmcons.h>
#include <assert.h>
#include <string>

#include "CConsole.h"
#include "CWindow.h"
#include "CNotification.h"
#include "CMessageBox.h"

#include "Resource.h"
#include "Error.h"
#include "Type.h"

#define GMEXPORT extern "C" __declspec (dllexport)

std::vector<Icon*> m_vIcon;

std::vector<CWindow*> m_vWindow;
std::vector<CNotification*> m_vNotification;

CConsole* m_pConsole;