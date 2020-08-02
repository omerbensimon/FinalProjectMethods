#pragma once

#include "../Common/Control.h"
#include <string>

using namespace std;

class Label : public Control
{
private:
    string label_text;
    static const size_t LABEL_HEIGHT = 1;

public:
    Label(int width);               //send width to control c'tor
    virtual ~Label() = default;
	virtual string getText() const;
	void setText(string value);
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
};