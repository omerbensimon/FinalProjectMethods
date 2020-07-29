#include "stdafx.h"
#include "SingelBorderPainter.h"

SingelBorderPainter::SingelBorderPainter() {
	borders[0] = (char)218;	//top-left
	borders[1] = (char)191;	//top-right
	borders[2] = (char)196;	//vertial-line
	borders[3] = (char)179;	//horizontal-line
	borders[4] = (char)192;	//bottom-left
	borders[5] = (char)217;	//bottom-right
}

void SingelBorderPainter::draw(Graphics &g, int left, int top, int width, int height) const {
	//paint top-left border
	if (top > 0 && left > 0) {
		g.write(left - 1, top - 1, string("") + borders[0]);
	}
	if (top > 0) {
		g.write(left, top - 1, string(width, borders[2]) + borders[1]);
	}

	for (int i = 0; i < height; i++) {
		if (left > 0) {
			g.write(left - 1, top + i, string(1, borders[3]));
		}

		g.write(left + width, top + i, string(1, borders[3]));
	}

	if (left > 0) {
		g.write(left - 1, top + height, string("") + borders[4]);
	}
	g.write(left, top + height, string(width, borders[2]) + borders[5]);

};