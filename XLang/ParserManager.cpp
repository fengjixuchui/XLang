#include "ParserManager.h"
void ParserManager::AddParser(unordered_map<string, XParseMothod> m) {
	unordered_map<string, XParseMothod>::iterator mit;
	for(mit = m.begin(); mit != m.end(); mit++)
	{
		this->Map[mit->first] = mit->second;
	}
}
bool ParserManager::Load(string FileName) {
	ParserLib tl;
	tl.FileName = FileName;
	tl.Module = LoadLib(FileName.data());
	if (!tl.Module) {
		return false;
	}

	XInitMothod p;
	LibMothod p = GetSymbol(tl.Module, string("XLModuleInit").c_str());
	if (!p) {
		FreeLib(tl.Module);
		return false;
	}
	ParserInfo i = p(XLVersion);
	this->Libs.push_back(tl);
	this->AddParser(i.Keywords);
	return true;
}
ParserManager::~ParserManager() {
	vector<ParserLib>::iterator pit;
	for (pit = this->Libs.begin(); pit != Libs.end(); pit++)
	{
		FreeLib(pit->Module);
	}
}