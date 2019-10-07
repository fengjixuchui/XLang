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