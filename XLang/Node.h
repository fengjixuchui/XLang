#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;
class Node;
class StackNode;
typedef void(*XKeywordAction)(StackNode*,stringstream*);
class NodeBase;
class NodeCode;
class NodePublic;
class NodeVar;
class Node{
public:
    Node* Parent;
    vector<Node*> Children;
    virtual void Parse(unordered_map<string,XKeywordAction> m);
    virtual string Build();
};

class StackNode {
public:
    Node *Pop();
    void Push(Node *obj);
    int Size();
    Node *Top();
private:
    vector<Node *> Stack;
};

class NodeBase: public Node{
public:
	//args
	stringstream* Stream;
	//mothods
	void Parse(unordered_map<string,XKeywordAction> m) override;
};
class NodeClass: public Node{
public:
    //args
    string name;
    vector<string> extend;
    //mothods
    string Build() override;
};
class NodeCode: public Node{
public:
    //args
    string code;
    //mothods
    explicit NodeCode(string _code);
    string Build() override;
};
class NodePublic: public Node{
public:
    string Build() override;
};
class NodeVar: public Node{
public:
    explicit NodeVar(string _name,string _init);
    string name = "";
    string init = "";
    string Build() override;
};