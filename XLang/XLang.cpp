// XLang.cpp: 定义应用程序的入口点。
//

#include "XLang.h"
using namespace std;

int main(int argc,char **argv)
{
	cout << "XL Compiler " << XL_Version <<endl;
	Node* RootNode = new Node();
	ParserManager* GlobalParserManager = new ParserManager();
	GlobalParserManager->Load(CompilerBaseInit);
	string outfile_name = "build.out";
	for (size_t i = 1; i < argc; i++)
	{
		string arg = string(argv[i]);
		if (arg.substr(0, 3) == "-p+") {
			if (!GlobalParserManager->Load(arg.substr(3))) {
				cerr << "Load Parser Module Failid: " << arg.substr(3)<<endl;
			}
			else {
				cout << arg.substr(3) << "Load Success" << endl;
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
		if (string(argv[i]).substr(0, 3) == "-c+") {
			cout << arg.substr(3) << "Parsing" << endl;
			fstream* FStream = new fstream(arg.substr(3), ios::in | ios::out);
			stringstream* SStream = new stringstream();
			(*SStream) << FStream->rdbuf();
			NodeBase* FileNode = new NodeBase();
			FileNode->Stream = SStream;
			FileNode->Parse();
			RootNode->Children.push_back(FileNode);
			continue;
		}
	}
	cout<< RootNode->Build() <<endl;
	return 0;
}
