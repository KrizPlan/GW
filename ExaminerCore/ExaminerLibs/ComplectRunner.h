#pragma once
#include "Complect.h"
#include <cmath>
class ComplectRunner
{
private:
	Complect complect;
	int currentQuestionNumber;
	int currentTestNumber;
	int numberOfCorrectAnswers;
	int numberOfAnsweredQuestions;
	std::vector<Question> skippedQuestions;
	bool allQuestionChecked;
	std::vector<Question>incorrectlyAnsweredQuestions;
	std::vector<int>selectedAnswers;
public:
	ComplectRunner();
	ComplectRunner(Complect);
	~ComplectRunner();
	bool complectIsOver() const;
	bool currentTestIsOver() const;
	const Complect& getComplect() const;
	const Question& getCurrentQuestion() const;
	const int& getCurrentTestNumber() const;
	const int& getCurrentQuestionNumber() const;
	const int& complectResult() const;
	const int& complectPercent() const;
	void toAnswer(const int&);
	void toSkipQuestion();
	Question getIncorrectlyAnsweredQuestion();
	const int getSelectedAnswer();
	bool getIncorrectlyAnsweredQuestionIsOver() const;
	const bool getComplectResultIsPerfect() const;
	void nextTest();
	void shuffleAll();
};

