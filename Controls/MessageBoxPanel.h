#include <string>
#include "Panel.h"

using namespace std;

class MessageBoxPanel :public Panel {
public:
	MessageBoxPanel(int height, int width);
	virtual ~MessageBoxPanel() = default;
	virtual string getText();
	virtual void setLayer(size_t layer);
	virtual string getResult();
	virtual void show();
	virtual void setText(string text);
	string getTitle();
	virtual void setTitle(string title);

protected:
	virtual void addControl(Control& control, int left, int top);
	struct AnswerListener : public Listener {
		AnswerListener(MessageBoxPanel& box) :_box(box) {}
		void Pressed(Button& b) {
			_box.hide();
			if ((_box._result = b.getText()) == "Cnl") {
				exit(0);
			}
		}
	private:
		MessageBoxPanel& _box;
		size_t _index;
	};
protected:
	Label _lblText;
	Label _lblTitle;
	string _result;
};

