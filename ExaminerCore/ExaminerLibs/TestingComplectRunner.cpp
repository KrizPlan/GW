#include "TestingComplectRunner.h"
#include <iostream>


TestingComplectRunner::TestingComplectRunner(const ComplectRunner &_complectRunner) : complectRunner(_complectRunner){
}


TestingComplectRunner::~TestingComplectRunner(){
}


void TestingComplectRunner::playingComplectInConsole() {
	std::vector<std::string> tmpQuestionAnswers;
	int selectedAnswer;
	std::cout << "     +!----- Starting Complect -----!+     " << std::endl;
	while (!complectRunner.complectIsOver()) {
		std::cout << "   ! Starting test number " << complectRunner.getCurrentTestNumber() + 1 << std::endl << std::endl;
		while (!complectRunner.currentTestIsOver())
		{
			std::cout << "   Question number " << complectRunner.getCurrentQuestionNumber() + 1 << std::endl;
			std::cout << complectRunner.getCurrentQuestion().getQuestionText() << std::endl;
			tmpQuestionAnswers = complectRunner.getCurrentQuestion().getAnswers();
			for (int i = 0; i < tmpQuestionAnswers.size(); i++) {
				std::cout << i + 1 << " : " << tmpQuestionAnswers[i] << std::endl;
			}
			selectedAnswer = (rand() % tmpQuestionAnswers.size()) + 1;
			std::cout << std::endl << "> " << selectedAnswer << std::endl;
			complectRunner.toAnswer(selectedAnswer - 1);
			std::cout << "------------------------------" << std::endl;
		}
		complectRunner.nextTest();
	}
	std::cout << std::endl << std::endl << "    Complect is over    " << std::endl << std::endl;
	std::cout << "Your result : " << complectRunner.complectResult() << std::endl;
}