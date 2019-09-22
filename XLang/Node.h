#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
class NodeBase;

class NodeBase {
public:
	//args
	stringstream* Stream;
	NodeBase* Parent;
	vector<NodeBase*> Children;
	//mothods
	virtual void Parse();
};