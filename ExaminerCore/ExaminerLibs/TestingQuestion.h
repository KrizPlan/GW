#pragma once
#include "Question.h"

class TestingQuestion {
private:
	Question testingQuest;
public:
	TestingQuestion(const Question&);
	~TestingQuestion();
	void printQuestionInConsole() const;
	void testRandomizeAnswer();
};