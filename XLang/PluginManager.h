//
// Created by Voidptr on 2019/10/3.
//
#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include "NodeApi.h"
#include "CrossLibrary.h"
#include "AppSettings.h"
using namespace std;
class PluginManager {
public:
    //args
    vector<CrossLibrary> LoadedPlugins;
    unordered_map<string,XKeywordAction> LoadedKeywords;

    //mothots
    bool Load(string FileName);
    void Load(XPluginInitMothod Init);
    void ImportKeyword(unordered_map<string,XKeywordAction> xmap);
};
