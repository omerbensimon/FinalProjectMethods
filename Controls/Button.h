#pragma once
#include <string>
#include "Label.h"

using namespace std;

class Button : public Label
{
private:
	vector<struct Listener*> listeners;

public:

    Button(int width);
    virtual ~Button() = default;
    
    void addListener(struct Listener &listener);
    virtual void Pressed();
	virtual void keyDown(int keyCode, char character);

};

struct Listener
{
	virtual void Pressed(Button &b) = 0;
};
