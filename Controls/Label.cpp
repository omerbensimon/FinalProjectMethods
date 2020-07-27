#include <iostream>
#include "Label.h"

Label::Label(int width) : Control(LABEL_HEIGHT, width) {
	setCanGetFocus(false);
}

string Label::getText() const {
	return label_text;
}

void Label::setText(string value) {
	label_text = value.substr(0, getWidth());
}

void Label::draw(Graphics &g, int left, int top, size_t layer) const {
	if (layer == getLayer() && isVisible()) {
		Control::draw(g, left, top, layer);
		g.write(getLeft() + left, getTop() + top, label_text + string(getWidth() - label_text.size(), ' '));
	}
}
