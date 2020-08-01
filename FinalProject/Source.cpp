#include <fstream>
#include "../Controls/Panel.h"
#include "../Controls/Label.h"
#include "../Controls/TextBox.h"
#include "../Controls/Button.h"
#include "../Controls/NumericBox.h"
#include "../Common/EventEngine.h"
#include "../Controls/ComboBox.h"
#include "../Controls/CheckList.h"
#include "../Controls/RadioBox.h"
#include "../Controls/MessageBoxPanel.h"

MessageBoxPanel msg(15, 30);

struct Listener : public MouseListener
{
	Listener(Panel &panel) : _panel(panel) {
		static int count;
		count = 0;
		out.open("order.txt", ofstream::out | ofstream::app);

	}
	void mousePressed(Button &btn, int x, int y, bool isLeft) {
		vector<Control*> controls;
		_panel.getAllControls(&controls);
		auto it = controls.begin();
		while (it != controls.end()) {
			out << (**it).getText() << "\n";
			it++;
		}
		msg.show();
	};
	~Listener() {
		out.close();
	}

private:
	Panel & _panel;
	ofstream out;
};

int main()
{
	Panel form;
	Label label(50);
	label.setText("Where you wants to FLY?!");
	form.addControl(label, 1, 1);

	TextBox from(20);
	from.setBorder(BorderType::SINGEL);
	from.setText("From");
	form.addControl(from, 2, 3);

	TextBox to(20);
	to.setBorder(BorderType::SINGEL);
	to.setText("To");
	form.addControl(to, 25, 3);

	Label label2(50);
	label2.setText("Num Of Passengers:");
	form.addControl(label2, 1, 5);

	NumericBox numeric(5, 10, 20);
	numeric.setBorder(BorderType::SINGEL);
	form.addControl(numeric, 2, 7);

	Label label3(50);
	label3.setText("Class:");
	form.addControl(label3, 1, 9);

	vector<string> options = {
		"Economy",
		"Business",
		"Exclusive"
	};
	ComboBox cb(10, options);
	cb.setBorder(BorderType::SINGEL);
	form.addControl(cb, 2, 11);


	msg.setBorder(BorderType::DOUBLE);
	msg.setTitle("ThankYou!");
	msg.setText("Enjoy From your vaction!");
	form.addControl(msg, 40, 7);


	Label label4(10);
	label4.setText("includes:");
	form.addControl(label4, 17, 9);

	vector<string> options2 = {
		"Luggages",
		"Insurance lost",
		"Accident insurance",
		"Pet cage"
	};

	CheckList cl(5, 20, options2);
	cl.setBorder(BorderType::NONE);
	form.addControl(cl, 18, 10);


	vector<string> options3 = {
		"One Way",
		"Round Trip"
	};

	RadioBox rl(5, 20, options3);
	form.addControl(rl, 2, 15);

	Button submit(10);
	submit.setText("Submit");
	submit.setBorder(BorderType::DOUBLE);
	form.addControl(submit, 2, 20);

	
	Listener listener(form);
	submit.addListener(listener);

	Control::setFocus(from);

	EventEngine engine;
	engine.run(form);

	return 0;
}

