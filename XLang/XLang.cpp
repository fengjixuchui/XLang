// XLang.cpp: 定义应用程序的入口点。
//

#include "XLang.h"
using namespace std;
void InitKeyword(unordered_map<string,XKeywordAction> *m);
int main(int argc,char **argv)
{
	cout << "XL Compiler " << ApplicationVersion <<endl;
	Node *RootNode = new Node();
    unordered_map<string,XKeywordAction> KeywordMap;
    InitKeyword(&KeywordMap);


	string outfile_name = "a.out";
	for (size_t i = 1; i < argc; i++)
	{
		string arg = string(argv[i]);
		if (arg.substr(0, 3) == "-o=") {
			outfile_name = arg.substr(3);
			continue;
		}
		if (string(argv[i]).substr(0, 2) == "-l") {
			continue;
		}
		if (string(argv[i]).substr(0, 3) == "-c+") {
			cout << arg.substr(3) << " Parsing" << endl;
			fstream* FStream = new fstream(arg.substr(3), ios::in | ios::out);
			stringstream* SStream = new stringstream();
			(*SStream) << FStream->rdbuf();
            FStream->close();
			NodeBase* FileNode = new NodeBase();
			FileNode->Stream = SStream;
			FileNode->Parse(KeywordMap);
			RootNode->Children.push_back(FileNode);
			continue;
		}
	}
	cout<< RootNode->Build() <<endl;
	return 0;
}
void InitKeyword(unordered_map<string,XKeywordAction> *m){
    (*m)["class"] = [](StackNode* Stack,stringstream* Stream){
        (*Stack).Push(new NodeClass());
        //Parse Class
    };
    (*m)["}"] = [](StackNode* Stack,stringstream* Stream){
        (*Stack).Pop();
    };
}