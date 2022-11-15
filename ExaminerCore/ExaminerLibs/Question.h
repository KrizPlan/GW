#pragma once
#include <string>
#include <vector>
class Question {
private:
	std::string questionText;
	std::vector<std::string> answers;
	int correctAnswer;
public:
	Question();
	Question(const std::string&,const std::vector<std::string>&, int);
	~Question();
	void setQuestionText(const std::string& );
	void setQuestionAnswers(const std::vector<std::string>&);
	void setCorrectAnswer(int);
	const std::string& getQuestionText() const;
	const std::vector<std::string>& getAnswers() const;
	const int& getCorrectAnswer() const;
	bool isAnswerCorrect(int) const;
	void randomizeAnswers();
};


