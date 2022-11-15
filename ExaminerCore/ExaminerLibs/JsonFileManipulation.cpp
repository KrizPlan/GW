#include "JsonFileManipulation.h"
#include <fstream>
#include <ctime>

JsonFileManipulation::JsonFileManipulation()
{
}


JsonFileManipulation::~JsonFileManipulation()
{
}


void JsonFileManipulation::saveComplectInJson(const Complect& _complect) {

	j = json(_complect);

	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H.%M.%S", &timeinfo);
	std::string strTime(buffer);

	std::ofstream file(directory + strTime + ".json", std::ios::out);
	if (!file) {
		throw std::exception("Cannot create file");
	}
	else {
		file << j;
		file.close();
	}
}


void JsonFileManipulation::saveComplectInJson(const Complect& _complect, const std::string& _fileName) {

	j = json(_complect);

	std::ofstream file(directory + _fileName + ".json", std::ios::out);
	if (!file) {
		throw std::exception("Cannot create file");
	}
	else {
		file << j;
		file.close();
	}
}


json& JsonFileManipulation::getJsonFromFile(const std::string& _fileName) {

	std::ifstream file(directory + _fileName + ".json", std::ios::in);
	if (!file) {
		throw std::exception("Cannot open file");
	}
	else {
		file >> j;
		file.close();
		return j;
	}
}


Complect JsonFileManipulation::getComplectFromJsonFile(const std::string& _fileName) {

	std::ifstream file(directory + _fileName + ".json", std::ios::in);
	if (!file) {
		throw std::exception("Cannot open file");
	}
	else {
		file >> j;
		file.close();
		Complect _complect = j.get<Complect>();
		return _complect;
	}
}