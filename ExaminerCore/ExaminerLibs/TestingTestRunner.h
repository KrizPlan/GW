#pragma once
#include "TestRunner.h"

class TestingTestRunner
{
private:
	TestRunner testRunner;
public:
	TestingTestRunner(TestRunner);
	~TestingTestRunner();
	void playTestInConsole();
};

