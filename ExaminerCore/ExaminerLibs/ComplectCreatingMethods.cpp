#include "ComplectCreatingMethods.h"


Complect creatingDefaultComplect() {
	std::vector<Question> questions;
	std::vector<Test> tests;
	questions.push_back(Question("First question of test 1", { "First answer on first question", "Second answer on first question","Third answer on first question (it's correct)","Fourths answer on first question" }, 2));
	questions.push_back(Question("Second question of test 1", { "First answer on second question", "Second answer on second question (it's correct)","Third answer on second question","Fourths answer on second question" }, 1));
	questions.push_back(Question("Third question of test 1", { "First answer on third question", "Second answer on third question","Third answer on third question (it's correct)","Fourths answer on third question" }, 2));
	questions.push_back(Question("Fourths question of test 1", { "First answer on fourths question", "Second answer on fourths question","Third answer on fourths question","Fourths answer on fourths question (it's correct)" }, 3));
	questions.push_back(Question("Fifth question of test 1", { "First answer on fifth question (it's correct)", "Second answer on fifth question","Third answer on fifth question","Fourths answer on fifth question" }, 0));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 2", { "First answer on first question", "Second answer on first question","Third answer on first question","Fourths answer on first question (it's correct)" }, 3));
	questions.push_back(Question("Second question of test 2", { "First answer on second question", "Second answer on second question","Third answer on second question (it's correct)","Fourths answer on second question" }, 2));
	questions.push_back(Question("Third question of test 2", { "First answer on third question", "Second answer on third question (it's correct)","Third answer on third question","Fourths answer on third question" }, 1));
	questions.push_back(Question("Fourths question of test 2", { "First answer on fourths question", "Second answer on fourths question (it's correct)","Third answer on fourths question","Fourths answer on fourths question" }, 1));
	questions.push_back(Question("Fifth question of test 2", { "First answer on fifth question", "Second answer on fifth question","Third answer on fifth question (it's correct)","Fourths answer on fifth question" }, 2));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 3", { "First answer on first question", "Second answer on first question","Third answer on first question","Fourths answer on first question (it's correct)" }, 3));
	questions.push_back(Question("Second question of test 3", { "First answer on second question (it's correct)", "Second answer on second question","Third answer on second question","Fourths answer on second question" }, 0));
	questions.push_back(Question("Third question of test 3", { "First answer on third question", "Second answer on third question","Third answer on third question","Fourths answer on third question (it's correct)" }, 3));
	questions.push_back(Question("Fourths question of test 3", { "First answer on fourths question", "Second answer on fourths question","Third answer on fourths question","Fourths answer on fourths question (it's correct)" }, 3));
	questions.push_back(Question("Fifth question of test 3", { "First answer on fifth question (it's correct)", "Second answer on fifth question","Third answer on fifth question","Fourths answer on fifth question" }, 0));
	tests.push_back(questions);

	Level lvl(20, 0.1, 0.7, 0.85, "Midle");

	Complect complect("First complect", lvl, tests);

	return complect;
}



std::vector<Complect> creatingComplectsVector() {
	std::vector<Question> questions;
	std::vector<Test> tests;
	questions.push_back(Question("First question of test 1 (Complect_1)",
		{ "First answer on first question (Complect_1)",
		"Second answer on first question (Complect_1)",
		"Third answer on first question (it's correct) (Complect_1)",
		"Fourths answer on first question (Complect_1)" },
		2));
	/*questions.push_back(Question("Second question of test 1 (Complect_1)",
		{ "First answer on second question (Complect_1)",
		"Second answer on second question (it's correct) (Complect_1)",
		"Third answer on second question (Complect_1)",
		"Fourths answer on second question (Complect_1)" },
		1));*/
	questions.push_back(Question("Third question of test 1 (Complect_1)",
		{ "First answer on third question (Complect_1)",
		"Second answer on third question (Complect_1)",
		"Third answer on third question (it's correct) (Complect_1)",
		"Fourths answer on third question (Complect_1)" },
		2));
	questions.push_back(Question("Fourths question of test 1 (Complect_1)",
		{ "First answer on fourths question (Complect_1)",
		"Second answer on fourths question (Complect_1)",
		"Third answer on fourths question (Complect_1)",
		"Fourths answer on fourths question (it's correct) (Complect_1)" },
		3));
	questions.push_back(Question("Fifth question of test 1 (Complect_1)",
		{ "First answer on fifth question (it's correct) (Complect_1)",
		"Second answer on fifth question (Complect_1)",
		"Third answer on fifth question (Complect_1)",
		"Fourths answer on fifth question (Complect_1)" },
		0));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 2 (Complect_1)",
		{ "First answer on first question (Complect_1)",
		"Second answer on first question (Complect_1)",
		"Third answer on first question (Complect_1)",
		"Fourths answer on first question (it's correct) (Complect_1)" },
		3));
	questions.push_back(Question("Second question of test 2 (Complect_1)",
		{ "First answer on second question (Complect_1)",
		"Second answer on second question (Complect_1)",
		"Third answer on second question (it's correct) (Complect_1)",
		"Fourths answer on second question (Complect_1)" },
		2));
	questions.push_back(Question("Third question of test 2 (Complect_1)",
		{ "First answer on third question (Complect_1)",
		"Second answer on third question (it's correct) (Complect_1)",
		"Third answer on third question (Complect_1)",
		"Fourths answer on third question (Complect_1)" },
		1));
	questions.push_back(Question("Fourths question of test 2 (Complect_1)",
		{ "First answer on fourths question (Complect_1)",
		"Second answer on fourths question (it's correct) (Complect_1)",
		"Third answer on fourths question (Complect_1)",
		"Fourths answer on fourths question (Complect_1)" },
		1));
	questions.push_back(Question("Fifth question of test 2 (Complect_1)",
		{ "First answer on fifth question (Complect_1)",
		"Second answer on fifth question (Complect_1)",
		"Third answer on fifth question (it's correct) (Complect_1)",
		"Fourths answer on fifth question (Complect_1)" },
		2));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 3 (Complect_1)",
		{ "First answer on first question (Complect_1)",
		"Second answer on first question (Complect_1)",
		"Third answer on first question (Complect_1)",
		"Fourths answer on first question (it's correct) (Complect_1)" },
		3));
	questions.push_back(Question("Second question of test 3 (Complect_1)",
		{ "First answer on second question (it's correct) (Complect_1)",
		"Second answer on second question (Complect_1)",
		"Third answer on second question (Complect_1)",
		"Fourths answer on second question (Complect_1)" },
		0));
	questions.push_back(Question("Third question of test 3 (Complect_1)",
		{ "First answer on third question (Complect_1)",
		"Second answer on third question (Complect_1)",
		"Third answer on third question (Complect_1)",
		"Fourths answer on third question (it's correct) (Complect_1)" },
		3));
	questions.push_back(Question("Fourths question of test 3 (Complect_1)",
		{ "First answer on fourths question (Complect_1)",
		"Second answer on fourths question (Complect_1)",
		"Third answer on fourths question (Complect_1)",
		"Fourths answer on fourths question (it's correct) (Complect_1)" },
		3));
	questions.push_back(Question("Fifth question of test 3 (Complect_1)",
		{ "First answer on fifth question (it's correct) (Complect_1)",
		"Second answer on fifth question (Complect_1)",
		"Third answer on fifth question (Complect_1)",
		"Fourths answer on fifth question (Complect_1)" },
		0));
	tests.push_back(questions);
	questions.clear();

	Level lvl(20, 0.1, 0.7, 0.85, "Midle");

	std::vector<Complect> complects;
	complects.push_back(Complect("First complect", lvl, tests));
	tests.clear();

	questions.push_back(Question("First question of test 1 (Complect_2)",
		{ "First answer on first question (Complect_2)",
		"Second answer on first question (Complect_2)",
		"Third answer on first question (it's correct) (Complect_2)",
		"Fourths answer on first question (Complect_2)" },
		2));
	questions.push_back(Question("Second question of test 1 (Complect_2)",
		{ "First answer on second question (Complect_2)",
		"Second answer on second question (it's correct) (Complect_2)",
		"Third answer on second question (Complect_2)",
		"Fourths answer on second question (Complect_2)" },
		1));
	questions.push_back(Question("Third question of test 1 (Complect_2)",
		{ "First answer on third question (Complect_2)",
		"Second answer on third question (Complect_2)",
		"Third answer on third question (it's correct) (Complect_2)",
		"Fourths answer on third question (Complect_2)" },
		2));
	questions.push_back(Question("Fourths question of test 1 (Complect_2)",
		{ "First answer on fourths question (Complect_2)",
		"Second answer on fourths question (Complect_2)",
		"Third answer on fourths question (Complect_2)",
		"Fourths answer on fourths question (it's correct) (Complect_2)" },
		3));
	questions.push_back(Question("Fifth question of test 1 (Complect_2)",
		{ "First answer on fifth question (it's correct) (Complect_2)",
		"Second answer on fifth question (Complect_2)",
		"Third answer on fifth question (Complect_2)",
		"Fourths answer on fifth question (Complect_2)" },
		0));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 2 (Complect_2)",
		{ "First answer on first question (Complect_2)",
		"Second answer on first question (Complect_2)",
		"Third answer on first question (Complect_2)",
		"Fourths answer on first question (it's correct) (Complect_2)" },
		3));
	questions.push_back(Question("Second question of test 2 (Complect_2)",
		{ "First answer on second question (Complect_2)",
		"Second answer on second question (Complect_2)",
		"Third answer on second question (it's correct) (Complect_2)",
		"Fourths answer on second question (Complect_2)" },
		2));
	questions.push_back(Question("Third question of test 2 (Complect_2)",
		{ "First answer on third question (Complect_2)",
		"Second answer on third question (it's correct) (Complect_2)",
		"Third answer on third question (Complect_2)",
		"Fourths answer on third question (Complect_2)" },
		1));
	questions.push_back(Question("Fourths question of test 2 (Complect_2)",
		{ "First answer on fourths question (Complect_2)",
		"Second answer on fourths question (it's correct) (Complect_2)",
		"Third answer on fourths question (Complect_2)",
		"Fourths answer on fourths question (Complect_2)" },
		1));
	questions.push_back(Question("Fifth question of test 2 (Complect_2)",
		{ "First answer on fifth question (Complect_2)",
		"Second answer on fifth question (Complect_2)",
		"Third answer on fifth question (it's correct) (Complect_2)",
		"Fourths answer on fifth question (Complect_2)" },
		2));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 3 (Complect_2)",
		{ "First answer on first question (Complect_2)",
		"Second answer on first question (Complect_2)",
		"Third answer on first question (Complect_2)",
		"Fourths answer on first question (it's correct) (Complect_2)" },
		3));
	questions.push_back(Question("Second question of test 3 (Complect_2)",
		{ "First answer on second question (it's correct) (Complect_2)",
		"Second answer on second question (Complect_2)",
		"Third answer on second question (Complect_2)",
		"Fourths answer on second question (Complect_2)" },
		0));
	questions.push_back(Question("Third question of test 3 (Complect_2)",
		{ "First answer on third question (Complect_2)",
		"Second answer on third question (Complect_2)",
		"Third answer on third question (Complect_2)",
		"Fourths answer on third question (it's correct) (Complect_2)" },
		3));
	questions.push_back(Question("Fourths question of test 3 (Complect_2)",
		{ "First answer on fourths question (Complect_2)",
		"Second answer on fourths question (Complect_2)",
		"Third answer on fourths question (Complect_2)",
		"Fourths answer on fourths question (it's correct) (Complect_2)" },
		3));
	questions.push_back(Question("Fifth question of test 3 (Complect_2)",
		{ "First answer on fifth question (it's correct) (Complect_2)",
		"Second answer on fifth question (Complect_2)",
		"Third answer on fifth question (Complect_2)",
		"Fourths answer on fifth question (Complect_2)" },
		0));
	tests.push_back(questions);
	questions.clear();
	//Level lvl(300, 0.1, 0.7, 0.85, "Midle");

	complects.push_back(Complect("Second complect", lvl, tests));
	tests.clear();

	questions.push_back(Question("First question of test 1 (Complect_3)",
		{ "First answer on first question (Complect_3)",
		"Second answer on first question (Complect_3)",
		"Third answer on first question (it's correct) (Complect_3)",
		"Fourths answer on first question (Complect_3)" },
		2));
	questions.push_back(Question("Second question of test 1 (Complect_3)",
		{ "First answer on second question (Complect_3)",
		"Second answer on second question (it's correct) (Complect_3)",
		"Third answer on second question (Complect_3)",
		"Fourths answer on second question (Complect_3)" },
		1));
	questions.push_back(Question("Third question of test 1 (Complect_3)",
		{ "First answer on third question (Complect_3)",
		"Second answer on third question (Complect_3)",
		"Third answer on third question (it's correct) (Complect_3)",
		"Fourths answer on third question (Complect_3)" },
		2));
	questions.push_back(Question("Fourths question of test 1 (Complect_3)",
		{ "First answer on fourths question (Complect_3)",
		"Second answer on fourths question (Complect_3)",
		"Third answer on fourths question (Complect_3)",
		"Fourths answer on fourths question (it's correct) (Complect_3)" },
		3));
	questions.push_back(Question("Fifth question of test 1 (Complect_3)",
		{ "First answer on fifth question (it's correct) (Complect_3)",
		"Second answer on fifth question (Complect_3)",
		"Third answer on fifth question (Complect_3)",
		"Fourths answer on fifth question (Complect_3)" },
		0));
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 2 (Complect_3)",
		{ "First answer on first question (Complect_3)",
		"Second answer on first question (Complect_3)",
		"Third answer on first question (Complect_3)",
		"Fourths answer on first question (it's correct) (Complect_3)" },
		3));
	questions.push_back(Question("Second question of test 2 (Complect_3)",
		{ "First answer on second question (Complect_3)",
		"Second answer on second question (Complect_3)",
		"Third answer on second question (it's correct) (Complect_3)",
		"Fourths answer on second question (Complect_3)" },
		2));
	questions.push_back(Question("Third question of test 2 (Complect_3)",
		{ "First answer on third question (Complect_3)",
		"Second answer on third question (it's correct) (Complect_3)",
		"Third answer on third question (Complect_3)",
		"Fourths answer on third question (Complect_3)" },
		1));
	questions.push_back(Question("Fourths question of test 2 (Complect_3)",
		{ "First answer on fourths question (Complect_3)",
		"Second answer on fourths question (it's correct) (Complect_3)",
		"Third answer on fourths question (Complect_3)",
		"Fourths answer on fourths question (Complect_3)" },
		1));
	/*questions.push_back(Question("Fifth question of test 2 (Complect_3)",
		{ "First answer on fifth question (Complect_3)",
		"Second answer on fifth question (Complect_3)",
		"Third answer on fifth question (it's correct) (Complect_3)",
		"Fourths answer on fifth question (Complect_3)" },
		2));*/
	tests.push_back(questions);
	questions.clear();
	questions.push_back(Question("First question of test 3 (Complect_3)",
		{ "First answer on first question (Complect_3)",
		"Second answer on first question (Complect_3)",
		"Third answer on first question (Complect_3)",
		"Fourths answer on first question (it's correct) (Complect_3)" },
		3));
	questions.push_back(Question("Second question of test 3 (Complect_3)",
		{ "First answer on second question (it's correct) (Complect_3)",
		"Second answer on second question (Complect_3)",
		"Third answer on second question (Complect_3)",
		"Fourths answer on second question (Complect_3)" },
		0));
	questions.push_back(Question("Third question of test 3 (Complect_3)",
		{ "First answer on third question (Complect_3)",
		"Second answer on third question (Complect_3)",
		"Third answer on third question (Complect_3)",
		"Fourths answer on third question (it's correct) (Complect_3)" },
		3));
	questions.push_back(Question("Fourths question of test 3 (Complect_3)",
		{ "First answer on fourths question (Complect_3)",
		"Second answer on fourths question (Complect_3)",
		"Third answer on fourths question (Complect_3)",
		"Fourths answer on fourths question (it's correct) (Complect_3)" },
		3));
	/*questions.push_back(Question("Fifth question of test 3 (Complect_3)",
		{ "First answer on fifth question (it's correct) (Complect_3)",
		"Second answer on fifth question (Complect_3)",
		"Third answer on fifth question (Complect_3)",
		"Fourths answer on fifth question (Complect_3)" },
		0));*/
	tests.push_back(questions);
	questions.clear();
	Level lvl2(1, 0.1, 0.7, 0.85, "Midle");

	complects.push_back(Complect("Third complect", lvl2, tests));
	tests.clear();

	return complects;
}


std::vector<Complect> getComplectVectorFromFiles(){


	wxSetWorkingDirectory("Complects");
	
	std::vector<Complect> tmpComplects;

	wxDir dir(wxGetCwd());
	if (!dir.IsOpened())
	{
		throw std::exception("Cannot open directory");
	}

	wxString filename;
	json jsonFileContent;
	std::string tmpStr;
	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES | wxDIR_DIRS);
	while (cont)
	{
		std::ifstream tmpFile(std::string(filename), std::ios::in);

		tmpFile >> jsonFileContent;

		tmpFile.close();


		tmpComplects.push_back(jsonFileContent.get<Complect>());

		cont = dir.GetNext(&filename);
	}

	return tmpComplects;

};