// XLang.cpp: 定义应用程序的入口点。
//

#include "XLang.h"
using namespace std;

int main(int argc,char **argv)
{
	cout << "XL Compiler " << ApplicationVersion <<endl;
	Node *RootNode = new Node();
	PluginManager pluginManager;
	pluginManager.Load(CompilerBaseInit);
	string outfile_name = "a.out";
	for (size_t i = 1; i < argc; i++)
	{
		string arg = string(argv[i]);
		if (arg.substr(0, 3) == "-p+") {
		    if(!pluginManager.Load(arg.substr(3))){
		        cerr<<"Load "<<arg.substr(3)<<" Error"<<endl;
		    }else{
                cout<<"Load "<<arg.substr(3)<<" Success"<<endl;
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
            FStream->close();
			NodeBase* FileNode = new NodeBase();
			FileNode->Stream = SStream;
			FileNode->KeywordMap = &pluginManager.LoadedKeywords;
			FileNode->Parse();
			RootNode->Children.push_back(FileNode);
			continue;
		}
	}
	cout<< RootNode->Build() <<endl;
	return 0;
}
