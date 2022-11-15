#pragma once
#include <string>
#include "Level.h"
#include "Test.h"

class Complect
{
private:
	std::string displayName;
	Level level;
	std::vector<Test> tests;
public:
	Complect();
	Complect(std::string, Level, std::vector<Test>);
	~Complect();
	void setDisplayName(const std::string&);
	void setLevel(const Level&);
	void setTests(const std::vector<Test>&);
	const std::string& getDisplayName() const;
	const Level& getLevel() const;
	const std::vector<Test>& getTests() const;
	std::vector<Test>& getTestsToChange();
	const int& getNumberOfQuestionsInComplect() const;
};

