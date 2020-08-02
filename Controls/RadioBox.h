#include <string>
#include "CheckList.h"
using namespace std;

class RadioBox : public CheckList {
public:
	RadioBox(int height, int width, vector<string> options);
	virtual ~RadioBox() = default;
	virtual size_t getSelectedIndex() const;
	virtual void setSelectedIndex(size_t index);
	virtual void clearSelection();
	virtual void setLayer(size_t layer);
	virtual bool includeControls() const { return false; };
	virtual string getText() const;

protected:
	virtual vector<size_t> getSelectedIndices() const;
	virtual void selectIndex(size_t index);
	virtual void deselectIndex(size_t index);

};
