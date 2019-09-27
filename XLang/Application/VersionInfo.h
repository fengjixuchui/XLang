#pragma once
#define XLVersion "1.0.0"
#ifdef WIN32
#include <Windows.h>
#define  CMODULE HMODULE
#define  LoadLib LoadLibraryA
#define  GetSymbol GetProcAddress
#define  FreeLib FreeLibrary
#define  LibMothod (FARPROC&)
#else
#include <dlfcn.h>
#define  CMODULE void *
#define  LoadLib dlopen
#define  GetSymbol dlsym
#define  FreeLib dlclose
#define  LibMothod
#endif