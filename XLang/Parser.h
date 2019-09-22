#pragma once
#include <iostream>
#include <unordered_map>
#include "Node.h"
using namespace std;
typedef void(*XParseMothod)();
struct ParserInfo
{
	string Name;
	string Version;
	unordered_map<string, XParseMothod> Keywords;
};
typedef ParserInfo(*XInitMothod)(string);