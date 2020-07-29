#pragma once

#include "BorderPainter.h"

class NullBorderPainter : public BorderPainter {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const {}
};