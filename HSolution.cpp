// HSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
// (PS.65)FormatDate
//  H Solution

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};
string ReadDateString(string message)
{
	string strDate;
	cout << message;
	getline(cin >> ws, strDate);
	return strDate;
}

vector <string> SplitString(string text, string del)
{
	short pos = 0;
	string word = "";
	vector <string> vString;
	while ((pos = text.find(del)) != text.npos)
	{
		word = text.substr(0, pos);
		if (word != "")
			vString.push_back(word);
		text.erase(0, pos + del.length());
	}

	if (!text.empty())
		vString.push_back(text);

	return vString;
}

stDate StringDateToStruct(string strDate, string del)
{
	stDate Date;
	vector <string> vString = SplitString(strDate, del);
	Date.Day = stoi(vString.at(0));
	Date.Month = stoi(vString.at(1));
	Date.Year = stoi(vString.at(2));

	return Date;
}

string DateToString(stDate Date, string del = "/")
{
	return to_string(Date.Day) + del + to_string(Date.Month) + del + to_string(Date.Year);
}

string ReplaceWord(string text, string wordToReplace, string ReplaceTo)
{
	short pos;
	while ((pos = text.find(wordToReplace)) != string::npos)
	{
		text = text.replace(pos, wordToReplace.length(), ReplaceTo);

		//pos = text.find(wordToReplace); // next
	}

	return text;
}

string FormatDate(stDate Date, string dateFormat = "dd/mm/yyyy")
{
	string formattedDate = "";
	formattedDate = ReplaceWord(dateFormat, "dd", to_string(Date.Day));
	formattedDate = ReplaceWord(formattedDate, "mm", to_string(Date.Month));
	formattedDate = ReplaceWord(formattedDate, "yyyy", to_string(Date.Year));

	return formattedDate;
}

int main()
{
	string strDate = ReadDateString("\n Please, Enter Date ?    ");
	stDate Date = StringDateToStruct(strDate, "/");

	cout << FormatDate(Date, "yyyy/mm/dd") << endl;
	cout << FormatDate(Date, "yyyy/dd/mm") << endl;
	cout << FormatDate(Date, "mm/yyyy/dd") << endl;
	cout << FormatDate(Date, "mm/dd/yyyy") << endl;
	cout << FormatDate(Date, "dd/yyyy/mm") << endl;
	cout << FormatDate(Date) << endl;

	// ----


	return 0;
}


