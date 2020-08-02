#include "Control.h"

Control* Control::_focus = nullptr;
Control::Control(int height, int width) :
	_top(0),
	_left(0),
	_width(width),
	_height(height),
	_layer(0),
	_border(BorderType::NONE),
	_background(Color::Black),
	_foreground(Color::White),
	_visible(true),
	_canGetFocus(false)
{
	if ((height < 0) || (width < 0))
	{
		throw "Invalid control height or width";
	}

	setLayer(0);
}
void Control::show()
{
	_visible = true;
}
void Control::hide()
{
	_visible = false;
}
bool Control::isVisible() const
{
	return _visible;
}
Color Control::getForeground() const
{
	return _foreground;
}
void Control::setForeground(Color color)
{
	_foreground = color;
}
Color Control::getBackground() const
{
	return _background;
}
void Control::setBackground(Color color)
{
	_background = color;
}
void Control::setBorder(BorderType border)
{
	_border = border;
}
Control* Control::getFocus()
{
	return _focus;
}
void Control::setFocus(Control &control)
{
	_focus = &control;
}
void Control::getAllControls(vector<Control*>* controls)
{
	if (controls != nullptr)
	{
		controls->push_back(this);
	}
}
int Control::getLeft() const
{
	return _left;
}
void Control::setLeft(int left)
{
	_left = left;
}
int Control::getTop() const
{
	return _top;
}
void Control::setTop(int top)
{
	_top = top;
}
int Control::getWidth() const
{
	return _width;
}
void Control::setWidth(int width)
{
	_width = width;
}
int Control::getHeight() const
{
	return _height;
}
void Control::setHeight(int height)
{
	_height = height;
}
size_t Control::getLayer() const
{
	return _layer;
}
void Control::setLayer(size_t layer)
{
	_layer = layer;
}
bool Control::canGetFocus() const
{
	return _canGetFocus && isVisible();
}
void Control::setCanGetFocus(bool canGetFocus)
{
	_canGetFocus = canGetFocus;
}
void Control::draw(Graphics & g, int left, int top, size_t layer) const
{
	if (layer > getLayer() || !isVisible())
	{
		return;
	}
	g.setBackground(_background);
	g.setForeground(_foreground);
	const BorderPainter& borderPainter = BorderFactory::getInstance().getBorderPainter(_border);
	borderPainter.draw(g, getLeft() + left, getTop() + top, getWidth(), getHeight());
}
void Control::Pressed(){}
void Control::keyDown(int keyCode, char keychar){}

BorderType Control::getBorder() {
	return _border;
}

