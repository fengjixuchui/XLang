#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Parser.h"
#include "VersionInfo.h"
using namespace std;
struct ParserLib {
	string FileName;
	CMODULE Module;
};
class ParserManager {
public:
	//args
	unordered_map<string, XParseMothod> Map;
	vector<ParserLib> Libs;
	//mothod
	~ParserManager();
	void AddParser(unordered_map<string, XParseMothod> m);
	bool Load(string FileName);
};