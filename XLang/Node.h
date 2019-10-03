#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "ParserManager.h"
#include "NodeApi.h"
using namespace std;
class NodeBase;

class NodeBase: public Node{
public:
	//args
	stringstream* Stream;
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
    r->Version = XL_Version;
    r->Keywords["class"] = [](vector<Node *> s){
        s.push_back(new NodeClass());
    };
    r->Keywords["}"] = [](vector<Node *> s){
        s.erase(s.begin()+s.size());
    };
    return r;
};