#include "Button.h"
#include "NumericBox.h"

struct NumericBoxUpdateListener : public MouseListener
{
	NumericBoxUpdateListener(NumericBox &box) : _box(box)
	{}

	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		if (b.getText() == "+")
		{
			_box.setValue(_box.getValue() + 1);
		}
		if (b.getText() == "-")
		{
			_box.setValue(_box.getValue() - 1);
		}
	}
public:
	NumericBox & _box;
};

NumericBox::NumericBox(int width, int min, int max) :
	Panel(HEIGHT, width),
	_btnMinus(1), _lblValue(width - 2), _btnPlus(1),
	_value(min), _min(0), _max(max-10)
{

	auto updateListener = new NumericBoxUpdateListener(*this);

	_btnMinus.setText("-");
	_btnMinus.addListener(*updateListener);
	_btnPlus.setText("+");
	_btnPlus.addListener(*updateListener);

	addControl(_btnMinus, 0, 0);
	addControl(_lblValue, 1, 0);
	addControl(_btnPlus, width - 1, 0);
}

void NumericBox::setValue(int value)
{
	if (value > _max)
	{
		_value = _max-10;
	}
	else if (value < 0)
	{
		_value = 0;
	}

	else
	{
		_value = value;
	}

	_lblValue.setText(to_string(_value));
}

int NumericBox::getValue() const{	return _value;}

int NumericBox::getMin() const{	return _min;}

int NumericBox::getMax() const{	return _max;}

/*void NumericBox::draw(Graphics & g, int left, int top, size_t layer) const {
<<<<<<< HEAD
	if (layer == getLayer() && isVisible()) {
		Control::draw(g, left, top, layer);
		g.write(getLeft() + left, getTop() + top, _text + string(getWidth() - _text.size(), ' '));
	}
=======
if (layer == getLayer() && isVisible()) {
Control::draw(g, left, top, layer);
g.write(getLeft() + left, getTop() + top, _text + string(getWidth() - _text.size(), ' '));
}
>>>>>>> e8893513d48bcce29775be9d9f4ca3555d774e5d
}*/

void NumericBox::addControl(Control & control, int left, int top)
{
	Panel::addControl(control, left, top);
}

void NumericBox::setLayer(size_t layer)
{
	for (auto c : _controls)
	{
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}

string NumericBox::getText() const {	return to_string(_value);}