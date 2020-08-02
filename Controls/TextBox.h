#pragma once

#include <string>
#include "Label.h"
using namespace std;

class TextBox : public Label {
private:
	int curserPos; 

public:
	TextBox(int width);
	virtual ~TextBox() = default;
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
    virtual void keyDown(int keyCode, char keychar);
};
