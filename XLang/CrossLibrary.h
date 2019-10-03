//
// Created by Voidptr on 2019/10/2.
//
#pragma once
#include <iostream>
using namespace std;

#ifdef WIN32
#include <Windows.h>
#define  CMODULE HMODULE
#define  LoadLib(a) LoadLibraryA((a).c_str())
#define  GetSymbol(a,b) GetProcAddress((a),(b).c_str())
#define  FreeLib(a) FreeLibrary((a))
#define  LibMothod (FARPROC&)
#else
#include <dlfcn.h>
#define  CMODULE void *
#define  LoadLib(a) dlopen((a).c_str())
#define  GetSymbol(a,b) dlsym((a),(b).c_str())
#define  FreeLib(a) dlclose((a))
#define  LibMothod
#endif

class CrossLibrary{
public:
    //args
    CMODULE Module;
    //mothods
    CrossLibrary(string FileName);
    ~CrossLibrary();
    void Close();
    void *Symbol(string Name);
    operator bool();
};