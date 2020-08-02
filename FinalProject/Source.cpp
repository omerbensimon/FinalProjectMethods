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
using namespace std;

MessageBoxPanel messageBox(20, 30);


static int applicationCounter = 1;

struct FormListener : public Listener
{
	FormListener(Panel &panel) : _panel(panel) {}

	void Pressed(Button &btn) {
		string app = "application" + to_string(applicationCounter) + ".txt";
		out.open(app, ofstream::out);
		vector<Control*> controls;
		_panel.getAllControls(&controls);
	
		out << (*controls[0]).getText() << "\n";
		out << "Name: " << (*controls[1]).getText() << "\n";
		out << "Email :" << (*controls[2]).getText() << "\n";
		out << "Age: " << (*controls[6]).getText() << "\n";
		out << "Sex :" << (*controls[9]).getText() << "\n";
		out << "Degree :" << (*controls[16]).getText() << "\n";
		out << "Programming Languages:" << (*controls[18]).getText() << "\n";
		
		messageBox.show();
		out.close();
		applicationCounter++;

	};
	~FormListener() {
	}

private:
	Panel & _panel;
	ofstream out;
};

int main()
{
	Panel applicationForm;
	Label headerLabel(30);
	headerLabel.setText("Job Application Form:");
	applicationForm.addControl(headerLabel, 1, 1);

	TextBox name(20);
	name.setBorder(BorderType::SINGEL);
	name.setText("Name");
	applicationForm.addControl(name, 2, 3);

	TextBox email(20);
	email.setBorder(BorderType::SINGEL);
	email.setText("Email");
	applicationForm.addControl(email, 2, 6);

	Label ageLabel(50);
	ageLabel.setText("Age:");
	applicationForm.addControl(ageLabel, 1, 8);

	NumericBox ageNumericBox(5, 18, 60);
	ageNumericBox.setBorder(BorderType::SINGEL);
	applicationForm.addControl(ageNumericBox, 2, 10);

	Label sexLabel(10);
	sexLabel.setText("Sex:");
	applicationForm.addControl(sexLabel, 1, 12);

	vector<string> sexOptions = {
		"Male",
		"Female"
	};

	RadioBox sexRL(5, 20, sexOptions);
	applicationForm.addControl(sexRL, 2, 13);

	Label degreeLabel(50);
	degreeLabel.setText("Degree:");
	applicationForm.addControl(degreeLabel, 1, 15);

	vector<string> degreeOptions = {
		"Associate",
		"Bachelor's",
		"Master's"
	};
	ComboBox degreeCB(12, degreeOptions);
	degreeCB.setBorder(BorderType::SINGEL);
	applicationForm.addControl(degreeCB, 2, 17);


	Label languageLabel(24);
	languageLabel.setText("programming languages:");
	applicationForm.addControl(languageLabel, 1, 19);

	vector<string> languageOptions = {
		"C++",
		"JAVA",
		"PYTHON",
		"JS"
	};

	CheckList languageCL(5, 20, languageOptions);
	languageCL.setBorder(BorderType::NONE);
	applicationForm.addControl(languageCL, 2, 20);

	

	Button submit(10);
	submit.setText("Submit");
	submit.setBorder(BorderType::DOUBLE);
	applicationForm.addControl(submit, 2, 26);

	messageBox.setBorder(BorderType::DOUBLE);
	messageBox.setTitle("application has been sent");
	messageBox.setText("ok - continue   ctl - Exit");
	applicationForm.addControl(messageBox, 40, 7);
	
	FormListener listener(applicationForm);
	submit.addListener(listener);

	Control::setFocus(name);

	EventEngine engine;
	engine.run(applicationForm);

	return 0;
}

