#include "ComplectRunner.h"

ComplectRunner::ComplectRunner() : complect() {
	currentQuestionNumber = 0;
	currentTestNumber = 0;
	numberOfCorrectAnswers = 0;
	numberOfAnsweredQuestions = 0;
	skippedQuestions.clear();
	incorrectlyAnsweredQuestions.clear();
	selectedAnswers.clear();
	allQuestionChecked = false;
}


ComplectRunner::ComplectRunner(Complect _complect) : complect(_complect) {
	currentQuestionNumber = 0;
	currentTestNumber = 0;
	numberOfCorrectAnswers = 0;
	numberOfAnsweredQuestions = 0;
	skippedQuestions.clear();
	incorrectlyAnsweredQuestions.clear();
	selectedAnswers.clear();
	allQuestionChecked = false;
}


ComplectRunner::~ComplectRunner() {

}


bool ComplectRunner::complectIsOver() const{
	return ((currentTestNumber >= complect.getTests().size())
		&& (skippedQuestions.empty())
		&& (allQuestionChecked));
}


bool ComplectRunner::currentTestIsOver() const {
	if (!allQuestionChecked) {
		return currentQuestionNumber >= complect.getTests()[currentTestNumber].getNumberOfQuestions();
	}
	else {
		return skippedQuestions.empty();
	}
}


const Complect& ComplectRunner::getComplect() const {
	return complect;
}


const Question& ComplectRunner::getCurrentQuestion() const {
	if (!allQuestionChecked) {
		return complect.getTests()[currentTestNumber].getOneQuestion(currentQuestionNumber);
	}
	else {
		return skippedQuestions[currentQuestionNumber];
	}
}


const int& ComplectRunner::getCurrentTestNumber() const {
	return currentTestNumber;
}


const int& ComplectRunner::getCurrentQuestionNumber() const{
	return currentQuestionNumber;
}


const int& ComplectRunner::complectResult() const {
	int numberOfAllQuestions = complect.getNumberOfQuestionsInComplect();
	if (numberOfAnsweredQuestions == numberOfAllQuestions) {
		double complectPercentage = (double)numberOfCorrectAnswers / numberOfAllQuestions;
		if (complectPercentage >= complect.getLevel().getMark5Threshold()) {
			return 5;
		}
		else if (complectPercentage >= complect.getLevel().getMark4Threshold()) {
			return 4;
		}
		else if (complectPercentage >= complect.getLevel().getMark3Threshold()) {
			return 3;
		}
		else {
			return 2;
		}
	}
	else {
		return 2;
	}
	return -1;
}


const int& ComplectRunner::complectPercent() const {
	int numberOfAllQuestions = complect.getNumberOfQuestionsInComplect();
	if (numberOfAnsweredQuestions == numberOfAllQuestions) {
		double complectPercentage = (double)numberOfCorrectAnswers / numberOfAllQuestions;
		return int(round(complectPercentage*100));
	}
	else {
		return 0;
	}
}


void ComplectRunner::toAnswer(const int &_answerNumber) {
	if (!allQuestionChecked) {
		if (currentTestIsOver())
			throw std::exception("Trying answer out of test");
		else {
			
			if (_answerNumber == complect.getTests()[currentTestNumber].getOneQuestion(currentQuestionNumber).getCorrectAnswer()) {
				numberOfCorrectAnswers++;
			}
			else {
				incorrectlyAnsweredQuestions.push_back(complect.getTests()[currentTestNumber].getOneQuestion(currentQuestionNumber));
				selectedAnswers.push_back(_answerNumber);
			}

			currentQuestionNumber++;
			numberOfAnsweredQuestions++;

		}
	}
	else {

		if (skippedQuestions.empty()) {
			throw std::exception("Trying answer out of test");
		}
		else {
			
			if (_answerNumber == skippedQuestions[currentQuestionNumber].getCorrectAnswer()) {
				numberOfCorrectAnswers++;
			}
			else {
				incorrectlyAnsweredQuestions.push_back(skippedQuestions[currentQuestionNumber]);
				selectedAnswers.push_back(_answerNumber);
			}
			numberOfAnsweredQuestions++;
			skippedQuestions.erase(skippedQuestions.begin() + currentQuestionNumber);
		}
	}
}


void ComplectRunner::toSkipQuestion() {
	if (!allQuestionChecked) {
		skippedQuestions.push_back(complect.getTests()[currentTestNumber].getOneQuestion(currentQuestionNumber));
		currentQuestionNumber++;
	}
	else {
		if (currentQuestionNumber == skippedQuestions.size() - 1) {
			currentQuestionNumber = 0;
		}
		else {
			currentQuestionNumber++;
		}
	}
	
}


Question ComplectRunner::getIncorrectlyAnsweredQuestion() {
	Question tmpQuestion = incorrectlyAnsweredQuestions[0];
	incorrectlyAnsweredQuestions.erase(incorrectlyAnsweredQuestions.begin());
	return tmpQuestion;
}


const int ComplectRunner::getSelectedAnswer() {
	int tmpInt = selectedAnswers[0];
	selectedAnswers.erase(selectedAnswers.begin());
	return tmpInt;
}


bool ComplectRunner::getIncorrectlyAnsweredQuestionIsOver() const {
	return (incorrectlyAnsweredQuestions.empty() || selectedAnswers.empty());
}


const bool ComplectRunner::getComplectResultIsPerfect() const {
	return complect.getNumberOfQuestionsInComplect() == numberOfCorrectAnswers;
}


void ComplectRunner::nextTest() {
	currentTestNumber++;
	currentQuestionNumber = 0;
	if (currentTestNumber >= complect.getTests().size()) {
		allQuestionChecked = true;
	}
	
}


void ComplectRunner::shuffleAll() {
	for (int i = 0; i < complect.getTests().size(); i++){
		for (int j = 0; j < complect.getTests()[i].getAllQuestions().size(); j++) {
			complect.getTestsToChange()[i].getAllQuestionsToChange()[j].randomizeAnswers();
		}
		complect.getTestsToChange()[i].randomizeQuestions();
	}
}