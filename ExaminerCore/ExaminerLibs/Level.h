#pragma once
#include <string>
class Level
{
private:
	int timePerQuestion;
	double mark3Threshold;
	double mark4Threshold;
	double mark5Threshold;
	std::string levelName;
public:
	Level();
	Level(int, double, double, double, std::string);
	~Level();
	void setTimePerQuestion(const int&);
	void setMark3Threshold(const double&);
	void setMark4Threshold(const double&);
	void setMark5Threshold(const double&);
	void setLevelName(const std::string&);
	const int& getTimePerQuestion() const;
	const double& getMark3Threshold() const;
	const double& getMark4Threshold() const;
	const double& getMark5Threshold() const;
	const std::string& getLevelName() const;
};

