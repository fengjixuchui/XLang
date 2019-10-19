#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"
#include "parser.h"
using namespace std;
void identsInit();
void symbolsInit();
int main(int argc,char **argv);
int main(int argc,char **argv) {
    std::cout << "XLang Compiler" << std::endl;
    std::cout << "Build: "<<__TIME__ << " "<<__DATE__ << std::endl;
    std::cout << "By LightwingTeam" << std::endl;
    identsInit();
    symbolsInit();
    Node *Root = new Node;
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        if(arg.substr(0,3) == "-f="){
            fstream file(arg.substr(3));
            stringstream *sfile = new stringstream();
            (*sfile) << file.rdbuf();
            file.close();
            (*Root).Pos.line = -1;
            (*Root).Pos.pos = -1;
            (*Root).Children.push_back(Parse(sfile));
        }
    }
    return 0;
}
void identsInit(){
    identsMap["return"] = TToken::Treturn;
    identsMap["require"] = TToken::Trequire;
    identsMap["func"] = TToken::Tfunction;
    identsMap["class"] = TToken::Tclass;
    identsMap["include"] = TToken::Tinclude;
    identsMap["public"] = TToken::Tpublic;
    identsMap["private"] = TToken::Tprivate;
    identsMap["static"] = TToken::Tstatic;
    identsMap["extern"] = TToken::Textern;
    identsMap["null"] = TToken::Tnull;
}
void symbolsInit(){
    identsMap["+"] = TToken::Tadd;
    identsMap["-"] = TToken::Tsub;
    identsMap["*"] = TToken::Tmul;
    identsMap["/"] = TToken::Tdiv;
    identsMap["&&"] = TToken::Tand;
    identsMap["||"] = TToken::Tor;
    identsMap["and"] = TToken::Tand;
    identsMap["or"] = TToken::Tor;
}