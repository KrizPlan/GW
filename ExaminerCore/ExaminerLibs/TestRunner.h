#pragma once
#include "Test.h"

class TestRunner
{
private:
	Test test;
	int currentQuestionNumber;
	int numberOfCorrectAnswers;
public:
	TestRunner(Test);
	~TestRunner();
	bool testIsOver() const;
	const Question& getCurrentQuestion() const;
	const int& getCurrentQuestionNumber() const;
	double testResult() const;
	void toAnswer(const int&);
};

