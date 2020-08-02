#pragma once

#include <vector>
#include "../Common/Control.h"

using namespace std;

class Panel : public Control
{
    protected:
	vector<Control*> _controls;
public:
	Panel(int height = 50, int width = 50);
	virtual ~Panel() = default;
	virtual void getAllControls (vector<Control*>* controls);	
	virtual void draw (Graphics &g, int left, int top, size_t layer) const;
	virtual void Pressed ();
	virtual void keyDown (int keyCode, char keychar);
	virtual void addControl (Control& control, int left, int top);
	virtual void setForeground (Color color);
	virtual void setBackground (Color color);
	virtual string getText() const { return string(""); };
	virtual bool includeControls() const { return true; };
};
