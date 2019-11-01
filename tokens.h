//
// Created by Voidptr on 2019/10/19.
//

#pragma once
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
enum TToken{
    //basic
    Tnull,
    Tclass,
    Tfunction,
    Treturn,
    Textern,
    Trequire,
    Tinclude,
    Tpublic,
    Tprivate,
    Tstatic,
    Tend,
    //maths
    Tadd,
    Tsub,
    Tmul,
    Tdiv,
    Tand,
    Tor,
    //type
    Tint,
    Tdouble,
    Tfloat,
    Tchar,
    Tbyte,
    Tvoid
};
