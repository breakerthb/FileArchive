#include "CNoSQL.h"
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

CNoSQL::CNoSQL()
{
}


CNoSQL::~CNoSQL()
{
}

void CNoSQL::Init(string strConfFile)
{
	/////////////////////
	// Read File
	std::ifstream fin(strConfFile.c_str(), std::ios::in);
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

		string strKey = strLine.substr(0, find);
		string strValue = strLine.substr(find + 1);
		m_mapConf.insert(map<string, string>::value_type(strKey, strValue));
	}

	fin.clear();
	fin.close();
}

string CNoSQL::GetValue(string strKey)
{
	map<string, string>::iterator it = m_mapConf.find(strKey);
	if (it == m_mapConf.end())
	{
		// no find
		cout << "NoSQL can not find the key: " << strKey.c_str() << endl;
		return "";
	}
	else
	{
		// find
		string strValue = it->second;
		
		return strValue;
	}
}