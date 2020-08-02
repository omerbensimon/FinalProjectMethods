#include "Panel.h"

Panel::Panel(int height, int width) : Control(height, width) {
	setCanGetFocus(false);
}

void Panel::getAllControls(vector<Control*>* controls) {
	if (controls != nullptr) {
		for (auto control : _controls) {
			if (control->includeControls()) {
				control->getAllControls(controls);
			}
			controls->push_back(control);
		}
	}
}

void Panel::draw(Graphics & g, int left, int top, size_t layer) const {
	if (layer >= getLayer() && isVisible()) {
		for (auto control : _controls) {
			control->draw(g, left + getLeft(), top + getTop(), layer);
		}
		Control::draw(g, left, top, layer);
	}
}

void Panel::Pressed() {
	if (!isVisible()) {
		return;
	}
	if (canGetFocus()) {
		Control::setFocus(*this);
	}
	for (auto control : _controls) {
		control->Pressed();
	}
}

void Panel::keyDown(int keyCode, char keychar) {
	if (!isVisible()) {
		return;
	}
	for (auto control : _controls) {
		control->keyDown(keyCode, keychar);
	}
}

void Panel::addControl(Control& control, int left, int top) {
	control.setLeft(left);
	control.setTop(top);
	_controls.push_back(&control);
}

void Panel::setForeground(Color color) {
	Control::setForeground(color);
	for (auto control : _controls) {
		control->setForeground(color);
	}
}

void Panel::setBackground(Color color) {
	Control::setBackground(color);
	for (auto control : _controls) {
		control->setBackground(color);
	}
}
