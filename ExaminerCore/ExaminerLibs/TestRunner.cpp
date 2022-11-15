#include "TestRunner.h"



TestRunner::TestRunner(Test _test) : test(_test){
	test.randomizeQuestions();
	currentQuestionNumber = 0;
	numberOfCorrectAnswers = 0;
}


TestRunner::~TestRunner() {

}


bool TestRunner::testIsOver() const{
	return currentQuestionNumber >= test.getNumberOfQuestions();
}


const Question& TestRunner::getCurrentQuestion() const{
	return test.getOneQuestion(currentQuestionNumber);
}


const int& TestRunner::getCurrentQuestionNumber() const {
	return currentQuestionNumber;
}

double TestRunner::testResult() const{
	return (double)numberOfCorrectAnswers / test.getNumberOfQuestions();
}


void TestRunner::toAnswer(const int &_answerNumber) {
	if (_answerNumber == test.getOneQuestion(currentQuestionNumber).getCorrectAnswer()) {
		numberOfCorrectAnswers++;
	}
	currentQuestionNumber++;
}