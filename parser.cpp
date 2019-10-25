//
// Created by Voidptr on 2019/10/18.
//

#include "parser.h"
unordered_map<string,TToken> identsMap;
unordered_map<string,TToken> mathsMap;

Node *Parse(stringstream *v) {
    Node *fNode = new Node;
    Node *sNode = fNode;
    string buffer;
    size_t line;size_t pos;
    char charbuffer;
    while((*v).get(charbuffer)){
        buffer.push_back(charbuffer);
        //行处理
        if(charbuffer == '\n') line++;
        pos++;
        MapseT token;
        if(Mapse(identsMap,buffer,token)){
            //成功在标识符表找到了
            NodeIdent *nNode = new NodeIdent;
            //位置
            (*nNode).Pos.line = line;
            (*nNode).Pos.pos = pos - token.length;
            //参数
            (*nNode).Type = token.token;
            (*nNode).Parent = fNode;
            (*sNode).Children.push_back((Node *)nNode);
            sNode = nNode;
        }
    }
    return fNode;
}


bool Mapse(unordered_map<string,TToken> map,string buffer,MapseT &t){
    for (auto item : map) {
        int pos = buffer.length()-item.first.length();
        pos = pos < 0 ? 0 : pos;
        if(buffer.substr(pos) == item.first){
            //发现在本表中存在
            t.token = item.second;
            t.length = item.first.length();
            t.ident = item.first;
            return true;
        }
    }
    return false;
}