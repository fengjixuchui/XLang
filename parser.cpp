//
// Created by Voidptr on 2019/10/18.
//

#include "parser.h"

Node *Parse(stringstream *v) {
    Node *fNode = new Node;
    string buffer;
    char cb;
    while((*v).get(cb)){
        buffer.push_back(cb);
        for (auto item : identsMap) {
            if(buffer.substr(buffer.length()-item.first.length()) == item.first){
                //Token Node
                NodeIdent newNode;
                newNode.Type = item.second;
                (*fNode).Children.push_back((Node *)&newNode);
            }
        }
    }
    return fNode;
}
