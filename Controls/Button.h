#pragma once
#include <string>
#include "Label.h"

using namespace std;


class Button : public Label
{
private:
	vector<struct MouseListener*> listeners;

public:

    Button(int width);
    virtual ~Button() = default;
    
    void addListener(struct MouseListener &listener);
    virtual void mousePressed(int x, int y, bool isLeft);

};

struct MouseListener
{
	virtual void mousePressed(Button &button, int x, int y, bool isLeft) = 0;
};
