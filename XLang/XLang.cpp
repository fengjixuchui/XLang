// XLang.cpp: 定义应用程序的入口点。
//

#include "XLang.h"
using namespace std;

int main(int argc,char **argv)
{
	cout << "XL Compiler " << XLVersion <<endl;
	ParserManager* GlobalParserManager = new ParserManager();
	string outfile_name = "build.out";
	for (size_t i = 1; i < argc; i++)
	{
		string arg = string(argv[i]);
		if (arg.substr(0, 3) == "-p+") {
			if (!GlobalParserManager->Load(arg.substr(3))) {
				cerr << "Load Parser Module Failid: " << arg.substr(3)<<endl;
			}
			continue;
		}
		if (arg.substr(0, 3) == "-o=") {
			outfile_name = arg.substr(3);
			continue;
		}
		if (string(argv[i]).substr(0, 2) == "-l") {
			continue;
		}
		if (string(argv[i]).substr(0, 2) == "-c") {
			continue;
		}
	}
	return 0;
}
