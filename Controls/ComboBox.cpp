#include "Button.h"
#include "ComboBox.h"

ComboBox::ComboBox(int width, vector<string> options) :
	Panel(TEXT_Y * (options.size()+1), width),
	_btnValue(width), _pnlOptions(TEXT_Y * options.size(), width),
	_selectedIndex(0), _options(options), _listBorder(BorderType::NONE), _listIndex(0), _oldLayer(0) {
	struct ShowListListener* listener = new struct ShowListListener(*this);
	_btnValue.addListener(*listener);
	_btnValue.setText("^");
	_pnlOptions.hide();
	int i = 0;
	while (i < options.size())
	{
		Button* btnOption = new Button(width);
		struct UpdateListener* listener = new struct UpdateListener(*this, i);
		btnOption->setText(options[i]);
		btnOption->addListener(*listener);
		btnOption->setLayer(4);
		_pnlOptions.addControl(*btnOption, 0, i);
		i++;
	}
	_pnlOptions.setLayer(4);
	addControl(_btnValue, 0, 0);
	addControl(_pnlOptions, 0, 1);
	setCanGetFocus(false);
}

size_t ComboBox::getSelectedIndex() const {
	return _selectedIndex; }

void ComboBox::setSelectedIndex(size_t index) {
	if ((index < 0) || (index >= _options.size())) {
		throw "invalid index"; }
	_selectedIndex = index;
	_pnlOptions.hide();
	_btnValue.setText(_options[index]);
	Panel::setBorder(BorderType::NONE);
	_btnValue.setBorder(_listBorder);
}

void ComboBox::addControl(Control & control, int left, int top) {
	Panel::addControl(control, left, top);
}

void ComboBox::setForeground(Color color) {
	Panel::setForeground(color);
	_btnValue.setForeground(color);
	_pnlOptions.setForeground(color);
}

void ComboBox::setBackground(Color color) {
	Panel::setBackground(color);
	_btnValue.setBackground(color);
	_pnlOptions.setBackground(color);
}

void ComboBox::setBorder(BorderType border) {
	_listBorder = border;
	if (_pnlOptions.isVisible()) {
		Panel::setBorder(_listBorder);
		_btnValue.setBorder(BorderType::NONE); }
	else {
		Panel::setBorder(BorderType::NONE);
		_btnValue.setBorder(_listBorder); }
}

void ComboBox::Pressed() {
	Panel::Pressed();
}

void ComboBox::keyDown(int keyCode, char character) {
	if ((this != Control::getFocus()) || (!_pnlOptions.isVisible())) {
		return; }

	int change = 0;
	switch (keyCode) {
	case VK_RETURN:
	case VK_SPACE:
		setSelectedIndex(_listIndex);
		return;
	case VK_DOWN:
		change = 1;
		break;
	case VK_UP:
		change = -1;
		break;
	default:
		return;
	}

	vector<Control*> controls;
	_pnlOptions.getAllControls(&controls);
	controls[_listIndex]->setBackground(getBackground());
	controls[_listIndex]->setForeground(getForeground());

	if ((change == -1) && (_listIndex == 0)) {
		_listIndex = controls.size() - 1; }
	else {
		_listIndex = (_listIndex + change) % controls.size(); }

	controls[_listIndex]->setBackground(getForeground());
	controls[_listIndex]->setForeground(getBackground());
}

void ComboBox::setLayer(size_t layer) {
	_btnValue.setLayer(layer);
	Panel::setLayer(layer);
}

string ComboBox::getText() const {
	return _btnValue.getText();
};
