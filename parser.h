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

static unordered_map<string,TToken> identsMap;

Node *Parse(stringstream *v);
