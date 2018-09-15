#include "CMoveFile.h"
#include <iostream>
using namespace std;

CMoveFile::CMoveFile()
{

}

CMoveFile::~CMoveFile()
{
}

void CMoveFile::Init(string strConfFile)
{
	m_nosql.Init(strConfFile);
}

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

string CMoveFile::Operate(string strFile)
{
	string strPrefix = GetPrefix(strFile);

	cout << strPrefix.c_str() << endl;
	string strDest = m_nosql.GetValue(strPrefix);
	if (strDest == "")
	{
		cout << "Please add process method into config file." << endl;
		return "";
	}
	else
	{
		string strCmd = "move /y \"";
		strCmd += strFile;
		strCmd += "\" ";
		strCmd += strDest.c_str();

		//cout << strCmd.c_str() << endl;
		return strCmd;
	}
}