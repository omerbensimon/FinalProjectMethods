#include <string>
#include "Panel.h"

using namespace std;

class MessageBox:public Panel{
public:
	MessageBox(int height, int width);
	virtual ~MessageBox() = default;
	virtual string getText();
    virtual void setLayer(size_t layer);
    virtual string getResult();
    virtual void show();
	virtual void setText(string text);
	string getTitle();
	virtual void setTitle(string title);

protected:
	virtual void addControl(Control& control, int left, int top);
	struct AnswerListener : public MouseListener{
		AnswerListener(MessageBox &box):_box(box){}
		void mousePressed(Button &b, int x, int y, bool isLeft){
			_box.hide();
			_box._result = b.getText();
		}
	private:
		MessageBox &_box;
		size_t _index;
	};
protected:
	Label _lblText;
	Label _lblTitle;
	string _result;
};

