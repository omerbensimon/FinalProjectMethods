#include "TextBox.h"

TextBox::TextBox(int width) : Label(width), curserPos(0) {
	setCanGetFocus(true);
}

void TextBox::draw(Graphics & g, int left, int top, size_t layer) const {
	if (!isVisible()) {
		return;
	}
	Label::draw(g, left, top, layer);
	if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + left + curserPos, getTop() + top);
	}
}

void TextBox::keyDown(int keyCode, char keychar) {
	if ((this != Control::getFocus()) || !isVisible()) {
		return;
	}

	int cursPosInBox = curserPos;
	bool deleteChar = false;

	switch (keyCode) {
	case VK_BACK:
		if (curserPos > 0) {
			--curserPos;
		}
		deleteChar = true;
		break;
	case VK_DELETE:
		deleteChar = true;
		break;
	case VK_RETURN:
		return;
	case VK_LEFT:
		if (curserPos > 0) {
			--curserPos;
		}
		return;
	case VK_RIGHT:
		if (curserPos < getText().size() - 1) {
			++curserPos;
		}
		return;
	default:
		break;
	}

	if (deleteChar) {
		if (cursPosInBox < getText().size()) {
			string textInBox = getText();
			textInBox = textInBox.substr(0, cursPosInBox) + textInBox.substr(cursPosInBox + 1, textInBox.size() - cursPosInBox);
			setText(textInBox);
		}
	}
	else if (keychar != '\0') {
		string textInBox;
		if (cursPosInBox < getText().size()) {
			textInBox = getText().substr(0, cursPosInBox) + keychar + getText().substr(cursPosInBox + 1, getText().size() - cursPosInBox);
		}
		else {
			textInBox = getText() + keychar;
		}
		setText(textInBox);
		if (curserPos < getWidth() - 1) {
			++curserPos;
		}
	}
}
