#pragma once

#include <Windows.h>
#include "Control.h"
#include "Graphics.h"


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
