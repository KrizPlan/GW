#pragma once
#include "JsonMethods.h"

class JsonFileManipulation
{
private:
	json j;
	const char* directory = "D:\\Users\\teacher\\Documents\\Examiner\\ExaminerCore\\Complects\\";
public:
	JsonFileManipulation();
	~JsonFileManipulation();
	void saveComplectInJson(const Complect&);
	void saveComplectInJson(const Complect&, const std::string&);
	json& getJsonFromFile(const std::string&);
	Complect getComplectFromJsonFile(const std::string&);
};

