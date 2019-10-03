#include "ParserManager.h"


void ParserManager::AddParser(unordered_map<string, XKeywordAction> m) {
	unordered_map<string, XKeywordAction>::iterator mit;
	for(mit = m.begin(); mit != m.end(); mit++)
	{
		this->Map[mit->first] = mit->second;
	}
}

bool ParserManager::Load(XPluginInitMothod mothod) {
    XPluginInitMothod h = mothod;
    PluginInfo *i = h(XL_Version);
    this->AddParser(i->Keywords);
    return true;
}

bool ParserManager::Load(string FileName) {
	CrossLibrary lib(FileName);
	if(!lib){
	    return false;
	}
	XPluginInitMothod p = (XPluginInitMothod)lib.Symbol("XLPluginInit");
	if (!p) {
		lib.Close();
		return false;
	}
    PluginInfo *i = p(XL_Version);
	this->Librarys.push_back(lib);
	this->AddParser(i->Keywords);
	return true;
}
ParserManager::~ParserManager() {
	vector<CrossLibrary>::iterator pit;
	for (pit = this->Librarys.begin(); pit != Librarys.end(); pit++)
	{
	    if(pit->Module != nullptr) {
            pit->Close();
        }
	}
}