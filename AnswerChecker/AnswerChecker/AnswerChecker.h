#include <fstream>
#include <string>
#include <vector>

#pragma once

#ifdef ANSWERCHECKER_EXPORTS
#define ANSWERCHECKER_API __declspec(dllexport)
#else
#define ANSWERCHECKER_API __declspec(dllimport)
#endif

 class ANSWERCHECKER_API AnswerChecker
{
public:

	AnswerChecker();
	AnswerChecker(std::string InputFileName, std::string AnswerFileName);
	~AnswerChecker();
	void SetFileName(std::string InputFileName, std::string AnswerFileName);
	int GetLines();
	bool CheckAnswers(std::vector <std::string>& MyAnswers);
	void GoToLine(int line);

	std::ifstream InputFile;
	std::ifstream AnswerFile;
	std::string InputFileName;
	std::string AnswerFileName;

	int Lines;


};
