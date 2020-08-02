#include "RadioBox.h"

RadioBox::RadioBox(int height, int width, vector<string> options) :
	CheckList(height, width, options) {}
size_t RadioBox::getSelectedIndex() const {
	if (_selectedIndices.empty()) {
		return -1;
	}
	return _selectedIndices[0];
}
void RadioBox::setSelectedIndex(size_t index) {
	selectIndex(index);
}
void RadioBox::clearSelection() {
	for (size_t oldSelect : getSelectedIndices()) {
		deselectIndex(oldSelect);
	}
}
vector<size_t> RadioBox::getSelectedIndices() const {
	return CheckList::getSelectedIndices();
}
void RadioBox::selectIndex(size_t index) {
	for (size_t oldSelect : getSelectedIndices()) {
		deselectIndex(oldSelect);
	}
	CheckList::selectIndex(index);
}
void RadioBox::deselectIndex(size_t index) {
	CheckList::deselectIndex(index);
}
void RadioBox::setLayer(size_t layer) {
	for (auto c : _controls) {
		c->setLayer(layer);
	}
	Panel::setLayer(layer);
}
string RadioBox::getText() const {
	return CheckList::getText();
}