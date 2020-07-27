#pragma once
#include "Control.h"
#include "Graphics.h"
#include <Windows.h>

class EventEngine {
private:
	Graphics graphics;
	HANDLE console;
	DWORD mode;

	void onChangeFocuse(Control &src, Control *dst);

public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control& control);
};
