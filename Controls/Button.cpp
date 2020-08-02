#include "Button.h"

Button::Button(int width) : Label(width) {
		setCanGetFocus(true);
}

void Button::addListener(Listener &listener) {
	listeners.push_back(&listener);
};

void Button::Pressed() {

	if (canGetFocus())	Control::setFocus(*this);
		for (auto listener : listeners)	listener->Pressed(*this);
	
	if (!isVisible())	return;

}
void Button::keyDown(int keyCode, char character) {
	if ((this != Control::getFocus()) || !isVisible()) {
		return;
	}
	switch (keyCode) {
	case VK_SPACE:
	case VK_RETURN:
		for (auto listener : listeners)	listener->Pressed(*this);
		return;
	default:
		break;
	}
}

