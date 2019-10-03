//
// Created by Voidptr on 2019/10/2.
//
#include "CrossLibrary.h"
CrossLibrary::CrossLibrary(string FileName) {
    this->Module = LoadLib(FileName);
}
CrossLibrary::~CrossLibrary() {
    FreeLib(this->Module);
}
void* CrossLibrary::Symbol(string Name) {
    return LibMothod GetSymbol(this->Module,Name);
}
void CrossLibrary::Close() {
    FreeLib(this->Module);
}
CrossLibrary::operator bool() {
    return (this->Module);
}