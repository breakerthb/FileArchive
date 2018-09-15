#pragma once
#include "CNoSQL.h"
#include <string>
using namespace std;

class CMoveFile
{
public:
	CMoveFile();
	~CMoveFile();
	void Init(string strConfFile);
	string Operate(string strFile);
private:
	CNoSQL m_nosql;
};

