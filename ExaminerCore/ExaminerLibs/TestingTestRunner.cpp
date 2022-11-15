#include "TestingTestRunner.h"
#include <iostream>



TestingTestRunner::TestingTestRunner(TestRunner _testRunner) : testRunner(_testRunner) {
}


TestingTestRunner::~TestingTestRunner() {

}


void TestingTestRunner::playTestInConsole(){
	std::cout << "   -----Starting test-----   " << std::endl;
	std::vector<std::string> tmpQuestionAnswers;
	while (!testRunner.testIsOver()) {
		std::cout << "------------------------------" << std::endl;
		std::cout << "   Question number " << testRunner.getCurrentQuestionNumber() + 1 << std::endl;
		std::cout << testRunner.getCurrentQuestion().getQuestionText() << std::endl;
		tmpQuestionAnswers = testRunner.getCurrentQuestion().getAnswers();
		for (int i = 0; i < tmpQuestionAnswers.size(); i++) {
			std::cout << " " << i + 1 << " : " << tmpQuestionAnswers[i] << std::endl;
		}
		int selectedAnswer = (rand() % tmpQuestionAnswers.size()) + 1;
		std::cout << std::endl << "> " << selectedAnswer << std::endl;
		testRunner.toAnswer(selectedAnswer - 1);
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "   -----Test is over-----   " << std::endl;
	std::cout << "Your result : " << testRunner.testResult() * 100 << "%" << std::endl;
}