#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#ifdef WIN32
//Win32Api
#include <Windows.h>
#define PluginMothod __declspec(dllexport) __cdecl
#else
#endif
using namespace std;
class Node;
class Node{
public:
    Node* Parent;
    vector<Node*> Children;
    virtual void Parse(){

    }
    virtual string Build(){
        vector<Node*>::iterator nit;
        string Buffer = "";
        for (nit = this->Children.begin(); nit != this->Children.end() ; nit++) {
            Buffer += (*nit)->Build();
        }
        return Buffer;
    }
};
typedef void(*XParserAction)(vector<Node *>,stringstream *);
struct ParseInfo {
    XParserAction nowParser;
    vector<Node *> *NodeStack;
};
typedef void(*XKeywordAction)(ParseInfo *);
struct PluginInfo
{
	string Name;
	string Version;
	unordered_map<string, XKeywordAction> Keywords;
};
typedef PluginInfo*(*XPluginInitMothod)(string);
