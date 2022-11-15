#include <iostream>
#include <ctime>
#include <fstream>
#include "ExaminerLibs/Complect.h"
#include "ExaminerLibs/JsonFileManipulation.h"
#include "ExaminerLibs/ComplectRunner.h"
#include "ExaminerLibs/ComplectCreatingMethods.h"
#include <wx/wx.h>
#include <wx/display.h>


#ifndef GLOBAL_EXAMINER_VARIABLE
#define GLOBAL_EXAMINER_VARIABLE
const bool FINISH_COMPLECT_ON_TIMER_END = true;
#endif

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	//Colors for app

	wxColor colorAnswerEmpty;
	wxColor colorAnswerCorrect;
	wxColor colorAnswerIncorrect;
	wxColor colorAnswerSelected;
	wxColor colorPrimary;
	wxColor colorSecondary;
	wxColor colorTextWhite;
	wxColor colorBorder;

	wxString timerString;
	wxString allTimeOnComplect;
	unsigned int timeAfterStart;
	unsigned int allTimeOnComlect;
	bool messageOnTimerEnd;
	ComplectRunner complectRunnerInWork;
	std::vector<Complect> complects;
	Question incorrectlyAnsweredQuestion;
	int numberOfIncorrectAnswer;

	wxPanel* panelUp;
	wxPanel* panelBorderUp;
	wxPanel* panelMiddle;
	wxPanel* panelBorderBottom;
	wxPanel* panelBottomLeft;
	wxPanel* panelBottomRight;

	wxBoxSizer* mainSizer;

	wxFont fontButton;
	wxFont fontHeader;
	wxFont fontSubHeader;
	wxFont fontCore;

	wxStaticText* personGroupNumberLabel;
	wxTextCtrl* personGroupNumberInput;
	wxStaticText* personSurenameLabel;
	wxTextCtrl* personSurenameInput;
	wxStaticText* personNameLabel;
	wxTextCtrl* personNameInput;
	wxButton* toLoginButton;
	wxStaticText* infoAboutPerson;
	

	wxStaticText* complectName;
	wxButton* toAnswerOnQuestionButton;
	wxButton* toSkipAnswerButton;
	wxStaticText* startText;
	wxComboBox* complectsChoose;
	wxButton* toStartButton;
	wxStaticText* questionText;
	std::vector<wxPanel*> questionAnswerPanels;
	std::vector<wxStaticText*> questionAnswersText;
	std::vector<bool> currentChoosenAnswer;
	wxStaticText* complectCompleted;
	wxStaticText* complectResult;
	wxButton* toCompleteComplectButton;
	wxButton* toViewErrorsButton;
	wxButton* toFinishViewErrorsButton;
	wxButton* toViewNextErrorButton;
	wxStaticText* timerText;

	wxTimer complectTimer;

	void onExit(wxCommandEvent&);
	void onLogin(wxCommandEvent&);
	void onStart(wxCommandEvent&);
	void onClickAnswerOnQuestionButton(wxCommandEvent&);
	void onClickSkipAnswerButton(wxCommandEvent&);
	void onCompleteComplectButton(wxCommandEvent&);
	void onViewErrorsButton(wxCommandEvent&);
	void onFinishViewErrorsButton(wxCommandEvent&);
	void onViewNextErrorButton(wxCommandEvent&);
	void onComplectTimer(wxTimerEvent&);
	void complectIsOver();
	void onClickAnswerPanel(wxMouseEvent&);
};
enum {
	exitButtonID = wxID_LAST + 1,
	personGroupNumberLabelID,
	personGroupNumberInputID,
	personSurenameLabelID,
	personSurenameInputID,
	personNameLabelID,
	personNameInputID,
	toLoginButtonID,
	infoAboutPersonID,

	complectNameID,
	toAnswerOnQuestionButtonID,
	toSkipAnswerButtonID,
	startTextID,
	complectsChooseID,
	toStartButtonID,
	questionTextID,
	questionAnswerPanelsID,
	questionAnswersTextID = questionAnswerPanelsID + 10,
	complectCompletedID = questionAnswersTextID + 10,
	complectResultID,
	toCompleteComplectButtonID,
	toViewErrorsButtonID,
	toFinishViewErrorsButtonID,
	toViewNextErrorButtonID,
	timerTextID,
	complectTimerID
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame("Examiner Test", wxPoint(0, 0), wxSize(1280, 960));
	frame->Show(true);
	
	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	ShowFullScreen(1);
	srand((unsigned)time(NULL));
	fontButton = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	fontHeader = wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	fontSubHeader = wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	fontCore = wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	colorAnswerEmpty = wxColor("#EAEAEA");
	colorAnswerCorrect = wxColor("#89DB8E");
	colorAnswerIncorrect = wxColor("#E56E7E");
	colorAnswerSelected = wxColor("#9BB9CD");
	colorPrimary = wxColor("#FCFCEE"); //DDFFFF
	colorSecondary = wxColor("#00665E");
	colorTextWhite = wxColor("#FFFFFF");
	colorBorder = wxColor("#FFFFFF");

	int borderSize = 1;

	panelUp = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1280, 150));
	panelUp->SetBackgroundColour(colorSecondary);

	panelBorderUp = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1280, borderSize));
	panelBorderUp->SetBackgroundColour(colorBorder);

	panelMiddle = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(10, 660));
	panelMiddle->SetBackgroundColour(colorPrimary);


	panelBorderBottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1280, borderSize));
	panelBorderBottom->SetBackgroundColour(colorBorder);

	panelBottomLeft = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(10, 150));
	panelBottomLeft->SetBackgroundColour(colorSecondary);

	panelBottomRight = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(10,150));
	panelBottomRight->SetBackgroundColour(colorSecondary);

	wxBoxSizer* sizerBottom = new wxBoxSizer(wxHORIZONTAL);

	sizerBottom->Add(panelBottomLeft, 5, wxEXPAND | wxALL, 0);
	sizerBottom->Add(panelBottomRight, 2, wxEXPAND | wxALL, 0);

	
	wxBoxSizer* sizerCore = new wxBoxSizer(wxVERTICAL);
	sizerCore->Add(panelUp, 15, wxEXPAND | wxALL, 0);
	sizerCore->Add(panelBorderUp, 0, wxEXPAND | wxALL, 0);
	sizerCore->Add(panelMiddle, 66, wxEXPAND | wxALL, 0);
	sizerCore->Add(panelBorderBottom, 0, wxEXPAND | wxALL, 0);
	sizerCore->Add(sizerBottom, 15, wxEXPAND | wxALL, 0);

	// Completed layout

	wxButton* buttonExit = new wxButton(panelBottomRight, exitButtonID, "Выход", wxPoint(225, 45), wxSize(80, 40));
	buttonExit->SetFont(fontButton);

	buttonExit->Bind(wxEVT_BUTTON, &MyFrame::onExit, this);


	// Person login
	//int loginPosition = wxDisplay().GetGeometry().GetWidth() / 2 - 110;
	int loginPosition = 1280 / 2 - 110;
	personGroupNumberLabel = new wxStaticText(panelMiddle, personGroupNumberLabelID, "Введите номер группы", wxPoint(loginPosition, 160));
	personGroupNumberLabel->SetFont(fontCore);

	personGroupNumberInput = new wxTextCtrl(panelMiddle, personGroupNumberInputID, "", wxPoint(loginPosition, 200), wxSize(200, 30));
	personGroupNumberInput->SetFont(fontCore);

	personSurenameLabel = new wxStaticText(panelMiddle, personSurenameLabelID, "Введите фамилию:", wxPoint(loginPosition + 15, 260));
	personSurenameLabel->SetFont(fontCore);

	personSurenameInput = new wxTextCtrl(panelMiddle, personSurenameInputID, "", wxPoint(loginPosition, 300), wxSize(200, 30));
	personSurenameInput->SetFont(fontCore);

	personNameLabel = new wxStaticText(panelMiddle, personNameLabelID, "Введите имя:", wxPoint(loginPosition + 45, 360));
	personNameLabel->SetFont(fontCore);

	personNameInput = new wxTextCtrl(panelMiddle, personNameInputID, "", wxPoint(loginPosition, 400), wxSize(200, 30));
	personNameInput->SetFont(fontCore);

	toLoginButton = new wxButton(panelMiddle, toLoginButtonID, "Отправить", wxPoint(loginPosition + 50, 500), wxSize(90, 35));
	toLoginButton->SetFont(fontButton);

	toLoginButton->Bind(wxEVT_BUTTON, &MyFrame::onLogin, this);

	infoAboutPerson = new wxStaticText(panelBottomLeft, infoAboutPersonID, "", wxPoint(40, 60));
	infoAboutPerson->SetFont(fontSubHeader);
	infoAboutPerson->SetOwnForegroundColour(colorTextWhite);
	infoAboutPerson->Hide();

	// Start panel

	startText = new wxStaticText(panelMiddle, startTextID, "Выберите комплект", wxPoint(400, 25));
	startText->SetFont(fontSubHeader);
	startText->Hide();

	complectsChoose = new wxComboBox(panelMiddle, complectsChooseID, "Комплекты", wxPoint(50, 80), wxSize(500, 50));
	complectsChoose->SetFont(fontCore);
	complectsChoose->Hide();
	
	complects = getComplectVectorFromFiles();
	
	for (auto tmpComplect : complects) {
		complectsChoose->Append(wxString::FromUTF8(tmpComplect.getDisplayName()));
	}


	toStartButton = new wxButton(panelMiddle, toStartButtonID, "Начать", wxPoint(750, 600), wxSize(90,40));
	toStartButton->SetFont(fontButton);
	toStartButton->Hide();

	toStartButton->Bind(wxEVT_BUTTON, &MyFrame::onStart, this);


	// Complect work

	complectName = new wxStaticText(panelUp, complectNameID, "");
	complectName->SetFont(fontHeader);
	complectName->SetForegroundColour(colorTextWhite);
	complectName->Hide();

	questionText = new wxStaticText(panelMiddle, questionTextID,"");
	questionText->SetFont(fontSubHeader);
	questionText->Hide();

	for (int i = 0; i < 6; i++) {
		questionAnswerPanels.push_back(new wxPanel(panelMiddle, questionAnswerPanelsID + i, wxPoint(50, 110 + 60 * i), wxSize(700, 50)));
		questionAnswerPanels[i]->SetBackgroundColour(colorAnswerEmpty);
		questionAnswerPanels[i]->Hide();
		questionAnswersText.push_back(new wxStaticText(questionAnswerPanels[i], questionAnswersTextID, "", wxPoint(20,15), wxDefaultSize));
		questionAnswersText[i]->SetFont(fontCore);
		questionAnswersText[i]->Hide();
	}

	toAnswerOnQuestionButton = new wxButton(panelMiddle, toAnswerOnQuestionButtonID, "");
	toAnswerOnQuestionButton->SetFont(fontButton);
	toAnswerOnQuestionButton->Hide();

	toSkipAnswerButton = new wxButton(panelMiddle, toSkipAnswerButtonID, "");
	toSkipAnswerButton->SetFont(fontButton);
	toSkipAnswerButton->Hide();

	timerText = new wxStaticText(panelMiddle, timerTextID, "00:00:00/00:00:00", wxDefaultPosition);
	timerText->SetFont(fontCore);
	timerText->Hide();


	complectCompleted = new wxStaticText(panelMiddle, complectCompletedID, "");
	complectCompleted->SetFont(fontSubHeader);
	complectCompleted->Hide();

	complectResult = new wxStaticText(panelMiddle, complectResultID, "");
	complectResult->SetFont(fontSubHeader);
	complectResult->Hide();
	
	toCompleteComplectButton = new wxButton(panelMiddle, toCompleteComplectButtonID, "");
	toCompleteComplectButton->SetFont(fontButton);
	toCompleteComplectButton->Hide();

	toViewErrorsButton = new wxButton(panelMiddle, toViewErrorsButtonID, "");
	toViewErrorsButton->SetFont(fontButton);
	toViewErrorsButton->Hide();

	toFinishViewErrorsButton = new wxButton(panelMiddle, toFinishViewErrorsButtonID, "");
	toFinishViewErrorsButton->SetFont(fontButton);
	toFinishViewErrorsButton->Hide();

	toViewNextErrorButton = new wxButton(panelMiddle, toViewNextErrorButtonID, "");
	toViewNextErrorButton->SetFont(fontButton);
	toViewNextErrorButton->Hide();

	complectTimer.Bind(wxEVT_TIMER, &MyFrame::onComplectTimer, this);
	
	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(sizerCore, 1, wxEXPAND);
	this->SetSizerAndFit(mainSizer);
	

}


void MyFrame::onExit(wxCommandEvent& e) {
	Close(true);
}


void MyFrame::onLogin(wxCommandEvent& e) {	
	if ((personGroupNumberInput->GetLineText(0) != "") &&
		(personSurenameInput->GetLineText(0) != "") &&
		(personNameInput->GetLineText(0) != "")) {
		
		wxString personGroupNumber = personGroupNumberInput->GetLineText(0);
		wxString personSurename = personSurenameInput->GetLineText(0);
		wxString pesronName = personNameInput->GetLineText(0);

		infoAboutPerson->SetLabel(personGroupNumber + " " + personSurename + " " + pesronName);
		infoAboutPerson->Show();

		personGroupNumberLabel->Hide();
		personGroupNumberInput->Hide();
		personSurenameLabel->Hide();
		personSurenameInput->Hide();
		personNameLabel->Hide();
		personNameInput->Hide();
		toLoginButton->Hide();
	
		startText->Show();
		complectsChoose->Show();
		toStartButton->Show();
	}
}


void MyFrame::onStart(wxCommandEvent& e) {
	if (complectsChoose->GetStringSelection() != "") {
		for (auto tmpComplect : complects) {
			if (wxString::FromUTF8(tmpComplect.getDisplayName()) == complectsChoose->GetStringSelection()) {
				complectRunnerInWork = ComplectRunner(tmpComplect);
				break;
			};
		}
		complectRunnerInWork.shuffleAll();
		//complectRunnerInWork = ComplectRunner(creatingDefaultComplect());
		complectsChoose->Hide();
		startText->Hide();
		toStartButton->Hide();

		for (int i = 0; i < questionAnswerPanels.size();i++) {
			questionAnswerPanels[i]->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)& MyFrame::onClickAnswerPanel, NULL, this);
		}
		allTimeOnComplect = "";
		allTimeOnComlect = (int)
			complectRunnerInWork.getComplect().getLevel().getTimePerQuestion() *
			complectRunnerInWork.getComplect().getNumberOfQuestionsInComplect();
		if (allTimeOnComlect / 3600 < 10) {
			allTimeOnComplect << 0;
		}
		allTimeOnComplect << allTimeOnComlect / 3600;
		allTimeOnComplect << ":";
		if ((allTimeOnComlect / 60) % 60 < 10) {
			allTimeOnComplect << 0;
		}
		allTimeOnComplect << (allTimeOnComlect / 60) % 60;
		allTimeOnComplect << ":";
		if (allTimeOnComlect % 60 < 10) {
			allTimeOnComplect << 0;
		}
		allTimeOnComplect << allTimeOnComlect % 60;
		timerString = "00:00:00/";
		timerString << allTimeOnComplect;
		timerText->SetLabel(timerString);
		timerText->SetPosition(wxPoint(950, 200));
		timerText->Show();
		timeAfterStart = 0;
		complectTimer.Start(1000);
		messageOnTimerEnd = false;
		

		complectName->SetLabel(wxString::FromUTF8(complectRunnerInWork.getComplect().getDisplayName()));
		complectName->SetPosition(wxPoint(550, 50));
		complectName->Show();

		questionText->SetLabel(wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getQuestionText()));
		questionText->SetPosition(wxPoint(250, 50));
		questionText->SetSize(wxSize(600, 50));
		questionText->Show();
		currentChoosenAnswer.clear();
		for (int i = 0; i < complectRunnerInWork.getCurrentQuestion().getAnswers().size(); i++) {
			questionAnswerPanels[i]->Show();
			questionAnswerPanels[i]->SetBackgroundColour(colorAnswerEmpty);
			wxString tmpWxString = wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getAnswers()[i]);
			questionAnswersText[i]->SetLabel(tmpWxString);
			questionAnswersText[i]->Show();
			currentChoosenAnswer.push_back(false);
		}

		

		toAnswerOnQuestionButton->SetLabel("Ответить");
		toAnswerOnQuestionButton->SetPosition(wxPoint(740, 600));
		toAnswerOnQuestionButton->SetSize(wxSize(100, 30));
		toAnswerOnQuestionButton->Bind(wxEVT_BUTTON, &MyFrame::onClickAnswerOnQuestionButton, this);
		toAnswerOnQuestionButton->Show();

		toSkipAnswerButton->SetLabel("Пропустить");
		toSkipAnswerButton->SetPosition(wxPoint(600, 600));
		toSkipAnswerButton->SetSize(wxSize(100, 30));
		toSkipAnswerButton->Bind(wxEVT_BUTTON, &MyFrame::onClickSkipAnswerButton, this);
		toSkipAnswerButton->Show();

	}

}



void MyFrame::onClickAnswerOnQuestionButton(wxCommandEvent& e) {


	int answerNumber = -1;
	for (int i = 0; i < currentChoosenAnswer.size(); i++) {
		if (currentChoosenAnswer[i]) {
			answerNumber = i;
		}
	}

	if (!complectRunnerInWork.complectIsOver()) {
		if (answerNumber >= 0) {

			for (int i = 0; i < complectRunnerInWork.getCurrentQuestion().getAnswers().size(); i++) {
				questionAnswersText[i]->Hide();
				questionAnswerPanels[i]->Hide();
			}
			currentChoosenAnswer.clear();

			questionAnswerPanels[answerNumber]->SetBackgroundColour(colorAnswerEmpty);
			complectRunnerInWork.toAnswer(answerNumber);

			if (complectRunnerInWork.currentTestIsOver()) {
				complectRunnerInWork.nextTest();
			}

			if (!complectRunnerInWork.complectIsOver()) {
				questionText->SetLabel(wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getQuestionText()));

				for (int i = 0; i < complectRunnerInWork.getCurrentQuestion().getAnswers().size(); i++) {
					questionAnswerPanels[i]->Show();
					wxString tmpWxString = wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getAnswers()[i]);
					questionAnswersText[i]->SetLabel(tmpWxString);
					questionAnswersText[i]->Show();
					currentChoosenAnswer.push_back(false);
				}

			}
			Refresh();
		}
	}
	if(complectRunnerInWork.complectIsOver()) {
		complectIsOver();
	}

	
}


void MyFrame::onClickSkipAnswerButton(wxCommandEvent& e) {
	if (!complectRunnerInWork.complectIsOver()) {
		
		for (int i = 0; i < complectRunnerInWork.getCurrentQuestion().getAnswers().size(); i++) {
			questionAnswersText[i]->Hide();
			questionAnswerPanels[i]->Hide();
		}
		currentChoosenAnswer.clear();
		
		complectRunnerInWork.toSkipQuestion();




		if (complectRunnerInWork.currentTestIsOver()) {
			complectRunnerInWork.nextTest();
		}

		if (!complectRunnerInWork.complectIsOver()) {
			questionText->SetLabel(wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getQuestionText()));

			for (int i = 0; i < complectRunnerInWork.getCurrentQuestion().getAnswers().size(); i++) {
				questionAnswerPanels[i]->Show();
				wxString tmpWxString = wxString::FromUTF8(complectRunnerInWork.getCurrentQuestion().getAnswers()[i]);
				questionAnswersText[i]->SetLabel(tmpWxString);
				questionAnswersText[i]->Show();
				currentChoosenAnswer.push_back(false);
			}

		}
		Refresh();
	
	}
	
}


void MyFrame::onCompleteComplectButton(wxCommandEvent& e) {
	complectCompleted->Hide();
	complectResult->Hide();
	toCompleteComplectButton->Hide();
	toViewErrorsButton->Hide();
	timerText->Hide();

	startText->Show();
	toStartButton->Show();
	complectsChoose->Show();
	complectsChoose->ChangeValue("Комплекты");
}


void MyFrame::onViewErrorsButton(wxCommandEvent& e) {

	complectCompleted->Hide();
	toCompleteComplectButton->Hide();
	toViewErrorsButton->Hide();

	complectResult->SetPosition(wxPoint(950,150));
	timerText->SetPosition(wxPoint(950, 200));

	toFinishViewErrorsButton->SetLabel("Закончить просмотр");
	toFinishViewErrorsButton->SetFont(fontButton);
	toFinishViewErrorsButton->SetSize(wxSize(160,40));
	toFinishViewErrorsButton->SetPosition(wxPoint(700,600));
	toFinishViewErrorsButton->Show();
	toFinishViewErrorsButton->Bind(wxEVT_BUTTON, &MyFrame::onFinishViewErrorsButton, this);

	toViewNextErrorButton->SetLabel("Следующая ошибка");
	toViewNextErrorButton->SetFont(fontButton);
	toViewNextErrorButton->SetSize(wxSize(160, 40));
	toViewNextErrorButton->SetPosition(wxPoint(500, 600));
	toViewNextErrorButton->Show();
	toViewNextErrorButton->Bind(wxEVT_BUTTON, &MyFrame::onViewNextErrorButton, this);

	incorrectlyAnsweredQuestion = complectRunnerInWork.getIncorrectlyAnsweredQuestion();
	numberOfIncorrectAnswer = complectRunnerInWork.getSelectedAnswer();

	if (complectRunnerInWork.getIncorrectlyAnsweredQuestionIsOver()) {
		toViewNextErrorButton->Hide();
	}

	complectName->Show();
	questionText->Show();
	questionText->SetLabel(wxString::FromUTF8(incorrectlyAnsweredQuestion.getQuestionText()));
	for (int i = 0; i < incorrectlyAnsweredQuestion.getAnswers().size(); i++) {
		
		questionAnswerPanels[i]->Show();
		questionAnswersText[i]->Show();
		questionAnswersText[i]->SetLabel(wxString::FromUTF8(incorrectlyAnsweredQuestion.getAnswers()[i]));
	}

	questionAnswerPanels[incorrectlyAnsweredQuestion.getCorrectAnswer()]->SetBackgroundColour(colorAnswerCorrect);
	questionAnswerPanels[numberOfIncorrectAnswer]->SetBackgroundColour(colorAnswerIncorrect);
	
	Refresh();

}


void MyFrame::onFinishViewErrorsButton(wxCommandEvent& e) {
	toFinishViewErrorsButton->Hide();
	toViewNextErrorButton->Hide();
	complectName->Hide();
	questionText->Hide();
	for (int i = 0; i < 6; i++) {
		questionAnswerPanels[i]->Hide();
		questionAnswersText[i]->Hide();
	}
	timerText->Hide();
	complectResult->Hide();

	startText->Show();
	toStartButton->Show();
	complectsChoose->Show();
	complectsChoose->ChangeValue("Комплекты");
}


void MyFrame::onViewNextErrorButton(wxCommandEvent& e) {
	questionAnswerPanels[incorrectlyAnsweredQuestion.getCorrectAnswer()]->SetBackgroundColour(colorAnswerEmpty);
	questionAnswerPanels[numberOfIncorrectAnswer]->SetBackgroundColour(colorAnswerEmpty);

	incorrectlyAnsweredQuestion = complectRunnerInWork.getIncorrectlyAnsweredQuestion();
	numberOfIncorrectAnswer = complectRunnerInWork.getSelectedAnswer();

	if (complectRunnerInWork.getIncorrectlyAnsweredQuestionIsOver()) {
		toViewNextErrorButton->Hide();
	}

	questionText->SetLabel(wxString::FromUTF8(incorrectlyAnsweredQuestion.getQuestionText()));
	for (int i = 0; i < incorrectlyAnsweredQuestion.getAnswers().size(); i++) {

		questionAnswerPanels[i]->Show();
		questionAnswersText[i]->Show();
		questionAnswersText[i]->SetLabel(wxString::FromUTF8(incorrectlyAnsweredQuestion.getAnswers()[i]));
	}

	questionAnswerPanels[incorrectlyAnsweredQuestion.getCorrectAnswer()]->SetBackgroundColour(colorAnswerCorrect);
	questionAnswerPanels[numberOfIncorrectAnswer]->SetBackgroundColour(colorAnswerIncorrect);

	Refresh();
}


void MyFrame::onComplectTimer(wxTimerEvent& e) {
	timerString.Clear();
	timerString = "";
	timeAfterStart++;
	if (timeAfterStart / 3600 < 10) {
		timerString << 0;
	}
	timerString << timeAfterStart / 3600;
	timerString << ":";
	if ((timeAfterStart / 60) % 60 < 10) {
		timerString << 0;
	}
	timerString << (timeAfterStart / 60) % 60;
	timerString << ":";
	if (timeAfterStart % 60 < 10) {
		timerString << 0;
	}
	timerString << timeAfterStart % 60;
	timerString << "/";
	timerString << allTimeOnComplect;
	timerText->SetLabel(timerString);

	if ((timeAfterStart >= allTimeOnComlect)&&(!messageOnTimerEnd)) {
		messageOnTimerEnd = true;
		if (FINISH_COMPLECT_ON_TIMER_END) {
			complectTimer.Stop();
			wxMessageBox("Время вышло!\nКомплект завершен.","Время вышло", wxOK);
			complectTimer.Start(1000);
			complectIsOver();
		}
		else {
			complectTimer.Stop();
			wxMessageBox("Время вышло!\nВы можете продолжить выполнять задания.", "Время вышло", wxOK);	
			complectTimer.Start(1000);
		}
	}
}


void MyFrame::complectIsOver() {
	complectName->Hide();
	questionText->Hide();
	for (int i = 0; i < 6; i++) {
		questionAnswersText[i]->Hide();
		questionAnswerPanels[i]->Hide();
		questionAnswerPanels[i]->Disconnect();
	}
	toAnswerOnQuestionButton->Hide();
	toSkipAnswerButton->Hide();

	complectTimer.Stop();

	//int complectCompletedPosition = wxDisplay().GetGeometry().GetWidth() / 2 - 120;
	int complectCompletedPosition = 1280 / 2 - 120;

	complectCompleted->SetLabel("Комплект завершен");
	complectCompleted->SetPosition(wxPoint(complectCompletedPosition, 235));
	complectCompleted->Show();

	wxString result = wxString("Оценка: ");
	result.Append(wxString::Format(wxT("%i"), complectRunnerInWork.complectResult()));
	result.Append(wxString(" ("));
	result.Append(wxString::Format(wxT("%i"), complectRunnerInWork.complectPercent()));
	result.Append(wxString("%) "));

	complectResult->SetLabel(result);
	complectResult->SetPosition(wxPoint(complectCompletedPosition + 22, 285));
	complectResult->Show();

	timerText->SetPosition(wxPoint(complectCompletedPosition + 28, 330));

	toCompleteComplectButton->SetLabel("Завершить");
	toCompleteComplectButton->SetPosition(wxPoint(complectCompletedPosition + 55, 365));
	toCompleteComplectButton->SetSize(wxSize(100, 30));
	toCompleteComplectButton->Bind(wxEVT_BUTTON, &MyFrame::onCompleteComplectButton, this);
	toCompleteComplectButton->Show();

	if (!complectRunnerInWork.getComplectResultIsPerfect() && !messageOnTimerEnd) {
		toViewErrorsButton->SetLabel("Посмотреть ошибки");
		toViewErrorsButton->SetPosition(wxPoint(complectCompletedPosition + 30, 420));
		toViewErrorsButton->SetSize(wxSize(160, 30));
		toViewErrorsButton->Bind(wxEVT_BUTTON, &MyFrame::onViewErrorsButton, this);
		toViewErrorsButton->Show();
	}
	
}


void MyFrame::onClickAnswerPanel(wxMouseEvent& e) {
	int panelNumber = e.GetId() - questionAnswerPanelsID;
	
	for (int i = 0; i < currentChoosenAnswer.size(); i++) {
		if (i == panelNumber) {
			if (currentChoosenAnswer[i]) {
				currentChoosenAnswer[i] = false;
				questionAnswerPanels[i]->SetBackgroundColour(colorAnswerEmpty);
			}
			else {
				currentChoosenAnswer[i] = true;
				questionAnswerPanels[i]->SetBackgroundColour(colorAnswerSelected);
			}
		}
		else {
			
			currentChoosenAnswer[i] = false;
			questionAnswerPanels[i]->SetBackgroundColour(colorAnswerEmpty);
		}
	}
	Refresh();
}