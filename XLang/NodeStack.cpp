//
// Created by Voidptr on 2019/10/4.
//

#include "Node.h"

Node *StackNode::Pop() {
    Node *r = this->Stack[this->Size()];
    this->Stack.erase(this->Stack.begin() + this->Size());
    return r;
}

Node *StackNode::Top() {
    Node *r = this->Stack[this->Size()];
    return r;
}

void StackNode::Push(Node *obj) {
    if(this->Size() != -1) {
        obj->Parent = this->Top();
        this->Top()->Children.push_back(obj);
    }
    this->Stack.push_back(obj);
}

int StackNode::Size() {
    return this->Stack.size() -1;
}
