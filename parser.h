//
// Created by Voidptr on 2019/10/18.
//
#pragma once
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "node.h"
#include "tokens.h"
using namespace std;
struct MapseT{
    size_t length;
    string ident;
    TToken token;
};
extern unordered_map<string,TToken> identsMap;
extern unordered_map<string,TToken> mathsMap;
Node *Parse(stringstream *v);
bool Mapse(unordered_map<string,TToken> map,string buffer,MapseT &t);