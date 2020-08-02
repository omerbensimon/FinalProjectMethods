#pragma once
#include <string>
#include "Button.h"
#include "Panel.h"
using namespace std;
class CheckList : public Panel
{
public:
	CheckList(int height, int width, vector<string> options);
	virtual ~CheckList() = default;
	virtual vector<size_t> getSelectedIndices() const;
	virtual void selectIndex(size_t index);
	virtual void deselectIndex(size_t index);
	virtual void Pressed();
	virtual void keyDown(int keyCode, char character);
	virtual void setLayer(size_t layer);
	virtual string getText() const;
	virtual bool includeControls() const { return false; };

protected:
	virtual void addControl(Control& control, int left, int top);
	virtual void alterSelectedIndex(size_t index);
protected:
	struct UpdateListener : public Listener
	{
		UpdateListener(CheckList &box, size_t index) : _box(box), _index(index){}
		void Pressed(Button &b)
		{
			_box.alterSelectedIndex(_index);
		}
	private:
		CheckList &_box;
		size_t _index;
	};
protected:
	vector<string> _options;
	vector<size_t> _selectedIndices;
	size_t _listIndex;
	static const size_t TEXT_Y = 1;
};
