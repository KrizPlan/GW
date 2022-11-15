#include "TestingQuestion.h"
#include <iostream>

TestingQuestion::TestingQuestion(const Question &_question) : testingQuest(_question){
}

TestingQuestion::~TestingQuestion() {

}


void TestingQuestion::printQuestionInConsole() const{
	std::cout << "Question:" << std::endl;
	std::cout << testingQuest.getQuestionText() << std::endl;
	std::vector<std::string> tmpAnswers = testingQuest.getAnswers();
	for (int i = 0; i < tmpAnswers.size(); ++i) {
		std::cout << i + 1 << "." << tmpAnswers[i] << std::endl;
	}
	std::cout << "Correct answer on position " << testingQuest.getCorrectAnswer() + 1 << std::endl;
	std::cout<<std::endl;
}


void TestingQuestion::testRandomizeAnswer() {
	int randomizeWorking = 1;
	std::cout << "Question before randomization" << std::endl;
	printQuestionInConsole();
	while (randomizeWorking)
	{
		testingQuest.randomizeAnswers();
		std::cout << "Question after randomization" << std::endl;
		printQuestionInConsole();
		std::cout << "Continue randomize (1 - y 0 - n)" << std::endl;
		std::cin >> randomizeWorking;
	}
}