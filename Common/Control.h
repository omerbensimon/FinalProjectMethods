#pragma once
#include <vector>
#include "Graphics.h"
#include "BorderFactory.h"
using namespace std;
class Control
{
protected:
	Control(int height, int width);
	virtual ~Control() = default;
public:
	virtual void show();
	virtual void hide();
	virtual bool isVisible() const;
	virtual Color getForeground() const;
	virtual void setForeground(Color color);
	virtual Color getBackground() const;
	virtual void setBackground(Color color);
	virtual void setBorder(BorderType border);
	virtual BorderType getBorder();
	static Control* getFocus();
	static void setFocus(Control &control);
	virtual void getAllControls(vector<Control*>* controls);
	int getLeft() const;
	virtual void setLeft(int left);
	int getTop() const;
	virtual void setTop(int top);
	int getWidth() const;
	virtual void setWidth(int width);
	int getHeight() const;
	virtual void setHeight(int height);
	size_t getLayer() const;
	virtual void setLayer(size_t layer);
	virtual bool canGetFocus() const;
	virtual void setCanGetFocus(bool canGetFocus); // TODO: set to protected
	virtual void draw(Graphics &g, int left, int top, size_t layer) const;
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);
	virtual string getText() const { return string(""); };

private:
	int _left;
	int _top;
	int _width;
	int _height;
	size_t _layer;
	BorderType _border;
	Color _background;
	Color _foreground;
	bool _visible;
	bool _canGetFocus;
	static Control* _focus;

};


