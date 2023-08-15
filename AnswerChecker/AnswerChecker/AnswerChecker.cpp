#include "pch.h"
#include "AnswerChecker.h"

AnswerChecker::AnswerChecker()
{
	InputFileName = "";
	AnswerFileName = "";
	Lines = NULL;
}

AnswerChecker::AnswerChecker(std::string InputFileName, std::string AnswerFileName)
{
	this->InputFileName = InputFileName;
	this->AnswerFileName = AnswerFileName;
	InputFile.open(this->InputFileName);
	AnswerFile.open(this->AnswerFileName);
	Lines = GetLines();
}

AnswerChecker::~AnswerChecker()
{
}

void AnswerChecker::SetFileName(std::string InputFileName, std::string AnswerFileName)
{
	this->InputFileName = InputFileName;
	this->AnswerFileName = AnswerFileName;
	InputFile.open(this->InputFileName);
	AnswerFile.open(this->AnswerFileName);
	Lines = GetLines();
}

int AnswerChecker::GetLines()
{
	int count{};
	std::string line;
	AnswerFile.seekg(std::ios::beg);
	while (AnswerFile.peek() != EOF)
	{
		getline(AnswerFile, line);
		count++;
	}
	return count;
}

bool AnswerChecker::CheckAnswers(std::vector <std::string> & MyAnswers)
{
	std::string line;
	AnswerFile.seekg(std::ios::beg);
	for (int i = 0; i < MyAnswers.size(); i++) {
		getline(AnswerFile, line);
		if (line != MyAnswers[i]) {
			return false;
		}
	}
	return true;
}

void AnswerChecker::GoToLine(int line)
{
}
