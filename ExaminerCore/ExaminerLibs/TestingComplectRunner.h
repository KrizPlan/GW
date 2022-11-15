#pragma once
#include "ComplectRunner.h"

class TestingComplectRunner
{
private:
	ComplectRunner complectRunner;
public:
	TestingComplectRunner(const ComplectRunner&);
	~TestingComplectRunner();
	void playingComplectInConsole();
};

