#include "Button.h"
#include "Label.h"
#include "MessageBox.h"

MessageBox::MessageBox(int height, int width):Panel(height, width), _lblText(width), _lblTitle(width-2){
	struct AnswerListener* listener = new struct AnswerListener(*this);

	if ((width < 12) || (height < 7))   throw "Width or Height is INVALID";
	auto btnOk = new Button(2);
	btnOk->setText("Ok");
	btnOk->addListener(*listener);

	auto btnCnl = new Button(6);
	btnCnl->setText("Cnl");
	btnCnl->addListener(*listener);

	setBorder(BorderType::SINGEL);
	_lblTitle.setBorder(BorderType::SINGEL);
	Panel::addControl(_lblTitle, 1, 1);
	Panel::addControl(_lblText, 0, 3);
	btnOk->setBorder(BorderType::SINGEL);
	Panel::addControl(*btnOk, 1, 5);
	btnCnl->setBorder(BorderType::SINGEL);
	Panel::addControl(*btnCnl, width-7, 5);
	hide();
}

void MessageBox::setLayer(size_t layer){
    for (auto c : _controls)
        c->setLayer(layer);
    Panel::setLayer(layer);
}

void MessageBox::addControl(Control & control, int left, int top) { addControl(control, left, top); };
string MessageBox::getTitle() { return _lblTitle.getText(); };
void MessageBox::setTitle(string title) { _lblTitle.setText(title); };
string MessageBox::getText() { return _lblText.getText(); };
void MessageBox::setText(string text) { _lblText.setText(text); };
string MessageBox::getResult() { return _result; };
void MessageBox::show(){
	_result = "";
	Panel::show();
}

