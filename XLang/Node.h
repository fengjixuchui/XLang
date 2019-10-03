#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "NodeApi.h"
using namespace std;
class NodeBase;

class NodeBase: public Node{
public:
	//args
	stringstream* Stream;
    unordered_map<string,XKeywordAction> *KeywordMap;
	//mothods
	virtual void Parse();
};
class NodeClass: public Node{
public:
    //args

    //mothods
    virtual void Parse();
};

XPluginInitMothod CompilerBaseInit = [] (string Version) -> PluginInfo* {
    PluginInfo* r = new PluginInfo();
    r->Name = "CompilerBase";
    r->Version = "1.0";
    r->Keywords["class"] = [](ParseInfo *s){
        s->NodeStack->push_back(new NodeClass());
    };
    r->Keywords["}"] = [](ParseInfo *s){
        s->NodeStack->erase(s->NodeStack->begin()+s->NodeStack->size());
    };
    return r;
};