//
// Created by Voidptr on 2019/10/18.
//

#include "node.h"

string Node::genCode() {
    string buffer;
    for (auto item : this->Children) {
        buffer += item->genCode();
    }
    return buffer;
}
