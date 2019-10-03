//
// Created by Voidptr on 2019/10/3.
//

#include "PluginManager.h"

void PluginManager::Load(XPluginInitMothod Init) {
    XPluginInitMothod initmothod = Init;
    PluginInfo *i = initmothod(ApplicationVersion);
    this->ImportKeyword(i->Keywords);
}

bool PluginManager::Load(string FileName) {
    CrossLibrary lib(FileName);
    if(!lib){
        return false;
    }
    XPluginInitMothod initmothod = lib.Symbol<XPluginInitMothod>("XPluginInit");
    if(!initmothod){
        lib.Close();
        return false;
    }
    PluginInfo *i = initmothod(ApplicationVersion);
    this->ImportKeyword(i->Keywords);
    this->LoadedPlugins.push_back(lib);
    return true;
}

void PluginManager::ImportKeyword(unordered_map<string,XKeywordAction> xmap) {
    for (auto mit = xmap.begin(); mit != xmap.end(); mit++) {
        pair<string,XKeywordAction> item  = (*mit);
        this->LoadedKeywords[item.first] = item.second;
    }
}
