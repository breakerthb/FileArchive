#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

string GetPrefix(string strFilePath)
{
	string strRet;
	int find = strFilePath.find_last_of(".");
	if (find != string::npos)
	{
		strRet = strFilePath.substr(find + 1);
	}
	return strRet;
}

map<string, string> g_mapAchive;

int main(int argc, char *argv[])
{
	/*for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}*/

	if (argc <= 2)
	{
		return 0;
	}

	/////////////////////
	// Read File
	std::ifstream fin(argv[1], std::ios::in);
	char line[1024] = { 0 };
	string strLine;

	while (fin.getline(line, sizeof(line)))
	{
		strLine = line;
		//cout << strLine << endl;
		int find = strLine.find("|");
		if (find == string::npos)
		{
			cout << "Config Error!" << endl;
			break;
		}

		string strA = strLine.substr(0, find);
		string strB = strLine.substr(find + 1);
		g_mapAchive.insert(map<string, string>::value_type(strA, strB));
	}

	fin.clear();
	fin.close();

	/////////////////////
	// Init Map
	//g_mapAchive.insert(map<string, string>::value_type("xlsx", "D:\\WorkBench\\Trash\\excel"));

	////////////////////
	// Operate
	//cout << argv[2] << endl;
	string strPrefix = GetPrefix(argv[2]);
	cout << strPrefix.c_str() << endl;
	map<string, string>::iterator it = g_mapAchive.find(strPrefix);
	if (it == g_mapAchive.end())
	{
		// no find
		cout << "Can not find : " << strPrefix.c_str() << endl;
		cout << "Please add process method into config file." << endl;
	}
	else
	{
		// find
		string strDest = it->second;
		string strCmd = "move /y \"";
		strCmd += argv[2];
		strCmd += "\" ";
		strCmd += strDest.c_str();

		cout << strCmd.c_str() << endl;
		system(strCmd.c_str());

	}

	//system("pause");
	return 0;
}