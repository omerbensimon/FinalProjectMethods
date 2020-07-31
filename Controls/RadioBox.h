#pragma once
#include <string>
#include "CheckList.h"
using namespace std;

class RadioList : public CheckList {
public:
	RadioList(int height, int width, vector<string> options);
	virtual ~RadioList() = default;
	virtual size_t getSelectedIndex() const;
	virtual void setSelectedIndex(size_t index);
	virtual void clearSelection();
	virtual void setLayer(size_t layer);
protected:
	virtual vector<size_t> getSelectedIndices() const;
	virtual void selectIndex(size_t index);
	virtual void deselectIndex(size_t index);

};
