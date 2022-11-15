#include "Test.h"

Test::Test() : questions({ { "Default question text", {"Default answer 1", "Default answer 2"}, 0 } }) {

}


Test::Test(std::vector<Question> _questions) : questions(_questions){
}


Test::~Test(){

}


void Test::setQuestions(const std::vector<Question> &_questions) {
	questions = _questions;
}


const std::vector<Question>& Test::getAllQuestions() const{
	return questions;
}


std::vector<Question>& Test::getAllQuestionsToChange() {
	return questions;
}


int Test::getNumberOfQuestions() const{
	return questions.size();
}


const Question& Test::getOneQuestion(int _questionNumber) const{
	return questions[_questionNumber];
}


void Test::randomizeQuestions() {
	for (int i = 0; i < questions.size(); i++) {
		questions[i].randomizeAnswers();
	}
	std::vector<Question> tmpQuestions = questions;
	questions.clear();
	int position;
	while (tmpQuestions.size() > 0) {
		position = rand() % tmpQuestions.size();
		questions.push_back(tmpQuestions[position]);
		tmpQuestions.erase(tmpQuestions.begin() + position);
	}
}