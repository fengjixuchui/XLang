//
// Created by Voidptr on 2019/10/18.
//
#pragma once
#include <iostream>
#include <vector>
#include "tokens.h"
using namespace std;
struct CodePos{
    int line;
    int pos;
};
class Node {
public:
    CodePos Pos;
    Node *Parent;
    vector<Node *> Children;
    virtual string genCode();
};
class NodeIdent:public Node {
public:
    TToken Type;
};