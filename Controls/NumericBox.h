#pragma once

#include <string>
#include "Panel.h"

using namespace std;

class NumericBox : public Panel
{
public:
	NumericBox(int width, int min, int max);
	virtual ~NumericBox() = default;
	virtual void setValue(int value);
	virtual string getText() const;
	int getValue() const;
	virtual int getMin() const;
	virtual int getMax() const;
	virtual void setLayer(size_t layer);

protected:
	virtual void addControl(Control& control, int left, int top);

protected:
	int _value;
	int _min;
	int _max;
	Button _btnMinus;
	Label _lblValue;
	Button _btnPlus;
	static const size_t HEIGHT = 1;
};