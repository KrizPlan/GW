#pragma once
#include "Question.h"
class Test{
private:
	std::vector<Question> questions;
public:
	Test();
	Test(std::vector<Question>);
	~Test();
	void setQuestions(const std::vector<Question>&);
	const std::vector<Question>& getAllQuestions() const;
	std::vector<Question>& getAllQuestionsToChange();
	int getNumberOfQuestions() const;
	const Question& getOneQuestion(int) const;
	void randomizeQuestions();
};

