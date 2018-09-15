#pragma once
#include <map>
using namespace std;

class CNoSQL
{
public:
	CNoSQL();
	~CNoSQL();
	void Init(string strConfFile);
	string GetValue(string strKey);


private:
	map<string, string> m_mapConf;
};

