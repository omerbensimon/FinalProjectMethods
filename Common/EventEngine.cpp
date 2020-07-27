#include "EventEngine.h"
#include <iostream>;
using namespace std;

EventEngine::EventEngine(DWORD i_word, DWORD o_word)
	:console(GetStdHandle(i_word)), graphics(o_word) {
	GetConsoleMode(console,&mode);
	SetConsoleMode(console, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

}

void EventEngine::run(Control& control) {
	bool paint_again = true;
		while (paint_again)
		{
		if (paint_again) {
			graphics.setCursorVisibility(false);
			graphics.clearScreen();
			for (size_t i = 0; i < 5; i++) {
				control.draw(graphics, control.getLeft(), control.getTop(), i);
			}
			paint_again= false;
		}

		INPUT_RECORD input_record;
		KEY_EVENT_RECORD key_event_record;
		DWORD flags = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

		ReadConsoleInput(console, &input_record, 1, &flags);
		key_event_record.bKeyDown = input_record.Event.KeyEvent.bKeyDown;
		switch (input_record.EventType && key_event_record.bKeyDown) {
		case KEY_EVENT:
		{
			Control* focused = Control::getFocus();
			auto rec_code = input_record.Event.KeyEvent.wVirtualKeyCode;
			auto rec_asciiChar = input_record.Event.KeyEvent.uChar.AsciiChar;
			if (rec_code == VK_TAB) {
				onChangeFocuse(control, focused);
			}
			else {
				focused->keyDown(rec_code, rec_asciiChar);
				paint_again = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			COORD pos = input_record.Event.MouseEvent.dwMousePosition;
			auto btn = input_record.Event.MouseEvent.dwButtonState;
			
			int y = pos.Y - control.getTop();
			int x = pos.X - control.getLeft();

			if (btn == FROM_LEFT_1ST_BUTTON_PRESSED || btn == RIGHTMOST_BUTTON_PRESSED) {
				control.mousePressed(x, y, btn == FROM_LEFT_1ST_BUTTON_PRESSED);
				paint_again= true;
			}
			break;
		}
		default:
			break;
		}
	}
}

void EventEngine::onChangeFocuse(Control &src, Control *dst) {
	vector<Control*> controls;
	src.getAllControls(&controls);

	auto it = find(controls.begin(), controls.end(), dst);
	do {
		if (++it == controls.end()) {
			it = controls.begin();
		}
	} while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}

