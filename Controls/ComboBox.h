
#pragma once
#include <string>
#include "Panel.h"
using namespace std;

class ComboBox : public Panel
{
public:
	ComboBox(int width, vector<string> options);
	virtual ~ComboBox() = default;
	virtual size_t getSelectedIndex() const;
	virtual void setSelectedIndex(size_t index);
	virtual void setForeground(Color color);
	virtual void setBackground(Color color);
	virtual void setBorder(BorderType border);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char character);
	virtual void setLayer(size_t layer);
	virtual string getText() const;
protected:
	virtual void addControl(Control& control, int left, int top);
protected:
	struct UpdateListener : public MouseListener {
		UpdateListener(ComboBox &box, size_t index) : _box(box), _index(index){}
		void mousePressed(Button &b, int x, int y, bool isLeft) {
			_box.setSelectedIndex(_index);
			_box.setLayer(_box._oldLayer);
			_box._oldLayer = 0;
			Control::setFocus(_box);
		}
	private:
		ComboBox &_box;
		size_t _index;
	};

	struct ShowListListener : public MouseListener {
		ShowListListener(ComboBox &box) : _box(box){}

		void mousePressed(Button &b, int x, int y, bool isLeft) {
			if (!_box._pnlOptions.isVisible()) {
				_box._pnlOptions.show();
				_box.Panel::setBorder(_box._listBorder);
				_box._btnValue.setBorder(BorderType::NONE);
				_box._oldLayer = _box.getLayer();
				_box.setLayer(4);
				Control::setFocus(_box);
			}
			else {
				_box._pnlOptions.hide();
				_box.Panel::setBorder(BorderType::NONE);
				_box._btnValue.setBorder(_box._listBorder);
				_box.setLayer(_box._oldLayer);
				_box._oldLayer = 0;
				Control::setFocus(_box);
			}
		}
	private:
		ComboBox &_box;
	};

protected:
	size_t _oldLayer;
	vector<string> _options;
	size_t _selectedIndex;
	size_t _listIndex;
	Panel _pnlOptions;
	Button _btnValue;
	BorderType _listBorder;
	static const size_t TEXT_Y = 1;
};
