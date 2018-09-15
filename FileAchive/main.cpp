#include <iostream>
#include "CMoveFile.h"

using namespace std;

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
	// Init Map
	CMoveFile moveFile;
	moveFile.Init(argv[1]);
	 
	////////////////////
	// Operate
	string strCmd = moveFile.Operate(argv[2]);
	cout << strCmd.c_str() << endl;
	system(strCmd.c_str());

	//system("pause");
	return 0;
}