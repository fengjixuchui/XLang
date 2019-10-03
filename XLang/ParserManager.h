#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "NodeApi.h"
#include "VersionInfo.h"
#include "CrossLibrary.h"
using namespace std;
class ParserManager {
public:
	//args
	unordered_map<string, XKeywordAction> Map;
	vector<CrossLibrary> Librarys;
	//mothod
	~ParserManager();
	void AddParser(unordered_map<string, XKeywordAction> m);
    bool Load(string FileName);
    bool Load(XPluginInitMothod mothod);
};