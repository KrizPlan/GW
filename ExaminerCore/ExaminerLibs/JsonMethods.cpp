#include "JsonMethods.h"

// JSON in/out methods for Question


void to_json(json& j, const Question& _quest) {
	j = json{
		{"questionText", _quest.getQuestionText()},
		{"answers", _quest.getAnswers()},
		{"correctAnswer", _quest.getCorrectAnswer()}
	};
}

void from_json(const json& j, Question& _quest) {
	std::string tmpQuestionText;
	j.at("questionText").get_to(tmpQuestionText);
	_quest.setQuestionText(tmpQuestionText);

	std::vector<std::string> tmpAnswers;
	j.at("answers").get_to(tmpAnswers);
	_quest.setQuestionAnswers(tmpAnswers);

	int tmpCorrectAnswer;
	j.at("correctAnswer").get_to(tmpCorrectAnswer);
	_quest.setCorrectAnswer(tmpCorrectAnswer);
}


// JSON in/out methods for Test

void to_json(json& j, const Test& _test) {
	j = json{ {"questions", _test.getAllQuestions()} };
}

void from_json(const json& j, Test& _test) {
	std::vector<Question> tmpQuestions;
	j.at("questions").get_to(tmpQuestions);
	_test.setQuestions(tmpQuestions);
}


// JSON in/out for Level

void to_json(json& j, const Level& _level) {
	j = json{
		{"timePerQuestion", _level.getTimePerQuestion()},
		{"mark3Threshold", _level.getMark3Threshold()},
		{"mark4Threshold", _level.getMark4Threshold()},
		{"mark5Threshold", _level.getMark5Threshold()},
		{"levelName", _level.getLevelName()}
	};
}

void from_json(const json& j, Level& _level) {
	int tmpTimePerQuestion;
	j.at("timePerQuestion").get_to(tmpTimePerQuestion);
	_level.setTimePerQuestion(tmpTimePerQuestion);

	double tmpMark3Threshold;
	j.at("mark3Threshold").get_to(tmpMark3Threshold);
	_level.setMark3Threshold(tmpMark3Threshold);

	double tmpMark4Threshold;
	j.at("mark4Threshold").get_to(tmpMark4Threshold);
	_level.setMark4Threshold(tmpMark4Threshold);

	double tmpMark5Threshold;
	j.at("mark5Threshold").get_to(tmpMark5Threshold);
	_level.setMark5Threshold(tmpMark5Threshold);

	std::string tmpLevelName;
	j.at("levelName").get_to(tmpLevelName);
	_level.setLevelName(tmpLevelName);
}


// JSON in/out for Complect

void to_json(json& j, const Complect& _complect) {
	j = json{
		{"displayName", _complect.getDisplayName()},
		{"level", _complect.getLevel()},
		{"tests", _complect.getTests()}
	};
}

void from_json(const json& j, Complect& _complect) {
	std::string tmpDisplayName;
	j.at("displayName").get_to(tmpDisplayName);
	_complect.setDisplayName(tmpDisplayName);

	Level tmpLevel;
	j.at("level").get_to(tmpLevel);
	_complect.setLevel(tmpLevel);

	std::vector<Test> tmpTests;
	j.at("tests").get_to(tmpTests);
	_complect.setTests(tmpTests);
}

