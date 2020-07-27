#include "Button.h"

Button::Button(int width) : Label(width) {}

void Button::addListener(MouseListener &listener) {
	listeners.push_back(&listener);
};

void Button::mousePressed(int x, int y, bool isLeft) {

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight()))
	{
		if (canGetFocus())	Control::setFocus(*this);
		for (auto listener : listeners)	listener->mousePressed(*this, x, y, isLeft);
	}
	if (!isVisible())	
        return;
}
