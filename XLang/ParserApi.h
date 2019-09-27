#pragma once
#include <iostream>
#include <unordered_map>
#ifdef WIN32
//Win32Api
#include <Windows.h>
#define PluginMothod __declspec(dllexport) __cdecl
#endif
using namespace std;
typedef void(*XParseMothod)();
struct ParserInfo
{
	string Name;
	string Version;
	unordered_map<string, XParseMothod> Keywords;
};
typedef ParserInfo(*XInitMothod)(string);
