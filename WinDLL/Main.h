#pragma once

#include "CWindow.h"
#include "Error.h"
#include <vector>
#include <Windows.h>
#include <Commctrl.h>
#include <Lmcons.h>
#include <assert.h>
#include <string>

#define GMEXPORT extern "C" __declspec (dllexport)

std::vector<CWindow*> Window;