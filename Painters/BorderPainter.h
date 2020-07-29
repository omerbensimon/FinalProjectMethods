#pragma once
#include "Graphics.h"

class BorderPainter {
public:
	virtual void draw(Graphics &g, int left, int top, int width, int height) const = 0;
};