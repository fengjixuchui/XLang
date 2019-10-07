// XLang.cpp: 定义应用程序的入口点。
//

#include "XLang.h"
using namespace std;
vector<string> splitString(string i,string a);
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
        //Parse Class
        string name;
        string extend;
        char c;
        bool extendPart = false;
        do{
            (!extendPart ? name : extend).push_back(c);
            c = 0;
            (*Stream) >> c;
            if(c==':'){
                extendPart=true;
            }
        }while(c != '{');
        //push Node
        NodeClass *cn = new NodeClass();
        cn->name = name;
        cn->extend = splitString(extend,",");
        Node *n = cn;
        (*Stack).Push(n);
    };
    (*m)["}"] = [](StackNode* Stack,stringstream* Stream){
        (*Stack).Pop();
    };
}
vector<string> splitString(string i,string a){
    if(i.find(a) == -1 || i.size() < a.size()){
        return vector<string>({ i });
    }
    vector<string> v;
    size_t o = 0;
    while (true){
        size_t t = i.find(a, o);
        v.push_back(i.substr(o,t - o));
        o = t + a.size();
        if(o == a.size() - 1){
            break;
        }
    }
    return v;
}