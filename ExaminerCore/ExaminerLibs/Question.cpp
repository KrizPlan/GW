#include "Question.h"
#include <iostream>

Question::Question() :questionText("Text"), answers({ "First", "Second" }), correctAnswer(0) {

}

Question::Question(const std::string &_questionText, const std::vector<std::string> &_answers, int _correctAnswer) : questionText(_questionText), answers(_answers), correctAnswer(_correctAnswer) {
}

Question::~Question(){
	
}


void Question::setQuestionText(const std::string &_question) {
	questionText = _question;
}


void Question::setQuestionAnswers(const std::vector<std::string> &_answers) {
	answers = _answers;
}


void Question::setCorrectAnswer(int _correctAnswer) {
	correctAnswer = _correctAnswer;
}


const std::string& Question::getQuestionText() const{
	return questionText;
}


const std::vector<std::string>& Question::getAnswers() const {
	return answers;
}


const int& Question::getCorrectAnswer() const {
	return correctAnswer;
}


bool Question::isAnswerCorrect(int _answer_number) const{
	return _answer_number == correctAnswer;
}


void Question::randomizeAnswers() {
	
	std::vector<std::string> tmpAnswers = answers;
	bool answerDidntChange = true;
	answers.clear();
	int position, iteration = 0;
	while (tmpAnswers.size()>0){
		position = rand() % tmpAnswers.size();
		if ((position == correctAnswer) && (answerDidntChange)) {
			correctAnswer = iteration;
			answerDidntChange = false;
		};
		if ((position < correctAnswer) && (answerDidntChange)) {
			correctAnswer--;
		}
		answers.push_back(tmpAnswers[position]);
		tmpAnswers.erase(tmpAnswers.begin() + position);
		iteration++;
	}
}