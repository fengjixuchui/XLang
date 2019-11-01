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
        if(arg.substr(0,3) == "-f+"){
            fstream file(arg.substr(3));
            stringstream *sfile = new stringstream();
            (*sfile) << file.rdbuf();
            file.close();
            (*Root).Pos.line = -1;
            (*Root).Pos.pos = -1;
            (*Root).Children.push_back(Parse(sfile));
        }
    }
    fstream outfile("tempfile.cpp");
    outfile << (*Root).genCode() << endl;
    outfile.close();
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
    identsMap["end"] = TToken::Tend;
    identsMap["}"] = TToken::Tend;
}
void symbolsInit(){
    mathsMap["+"] = TToken::Tadd;
    mathsMap["-"] = TToken::Tsub;
    mathsMap["*"] = TToken::Tmul;
    mathsMap["/"] = TToken::Tdiv;
    mathsMap["&&"] = TToken::Tand;
    mathsMap["||"] = TToken::Tor;
    mathsMap["and"] = TToken::Tand;
    mathsMap["or"] = TToken::Tor;
}