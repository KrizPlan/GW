#include "Level.h"



Level::Level() :
	timePerQuestion(300), 
	mark3Threshold(0.5),
	mark4Threshold(0.7),
	mark5Threshold(0.85),
	levelName("Default")
{

}

Level::Level(int _timePerQuestion, double _mark3Threshold, double _mark4Threshold, double _mark5Threshold, std::string _levelName) : levelName(_levelName) {
	timePerQuestion = _timePerQuestion;
	mark3Threshold = _mark3Threshold;
	mark4Threshold = _mark4Threshold;
	mark5Threshold = _mark5Threshold;
}


Level::~Level() {

}


void Level::setTimePerQuestion(const int& _timePerQuestion) {
	timePerQuestion = _timePerQuestion;
}


void Level::setMark3Threshold(const double& _mark3Threshold) {
	mark3Threshold = _mark3Threshold;
}


void Level::setMark4Threshold(const double& _mark4Threshold) {
	mark4Threshold = _mark4Threshold;
}


void Level::setMark5Threshold(const double& _mark5Threshold) {
	mark5Threshold = _mark5Threshold;
}


void Level::setLevelName(const std::string& _levelName) {
	levelName = _levelName;
}


const int& Level::getTimePerQuestion() const {
	return timePerQuestion;
}


const double& Level::getMark3Threshold() const {
	return mark3Threshold;
}


const double& Level::getMark4Threshold() const {
	return mark4Threshold;
}


const double& Level::getMark5Threshold() const {
	return mark5Threshold;
}


const std::string& Level::getLevelName() const {
	return levelName;
}