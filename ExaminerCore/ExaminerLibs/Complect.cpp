#include "Complect.h"



Complect::Complect() :
	displayName("Default Complect"),
	level(Level())
{
	tests.resize(1); 
}

Complect::Complect(std::string _displayName, Level _level, std::vector<Test> _tests) : displayName(_displayName), level(_level), tests(_tests) {
}


Complect::~Complect() {

}


void Complect::setDisplayName(const std::string &_displayName) {
	displayName = _displayName;
}


void Complect::setLevel(const Level& _level) {
	level = _level;
}


void Complect::setTests(const std::vector<Test>& _tests) {
	tests = _tests;
}


const std::string& Complect::getDisplayName() const {
	return displayName;
}


const Level& Complect::getLevel() const {
	return level;
}


const std::vector<Test>& Complect::getTests() const {
	return tests;
}


std::vector<Test>& Complect::getTestsToChange() {
	return tests;
};


const int& Complect::getNumberOfQuestionsInComplect() const {
	int tmpNumber = 0;
	for (auto test : tests) {
		tmpNumber += test.getNumberOfQuestions();
	}
	return tmpNumber;
}