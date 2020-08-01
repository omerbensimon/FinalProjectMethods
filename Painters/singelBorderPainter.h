#pragma once

#include "../Painters/BorderPainter.h"

class SingelBorderPainter : public BorderPainter {  
public:
	SingelBorderPainter();
	virtual void draw(Graphics &g, int left, int top, int width, int height) const; 
protected:
	char borders[6];
};