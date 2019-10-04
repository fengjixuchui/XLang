#include "Node.h"
void Node::Parse(unordered_map<string,XKeywordAction> a) {

}
string Node::Build() {
    vector<Node *>::iterator nit;
    string Buffer;
    for (nit = this->Children.begin(); nit != this->Children.end(); nit++) {
        Buffer += (*nit)->Build();
    }
    return Buffer;
}
void NodeBase::Parse(unordered_map<string,XKeywordAction> m) {
    bool stringing = false;
    StackNode Stack; Stack.Push(this);
    string Buffer;
    do{
        char i = 0;
        (*this->Stream) >> i;
        Buffer.push_back(i);
        unordered_map<string,XKeywordAction>::iterator miter;
        for (miter = m.begin(); miter != m.end() ; miter++) {
            pair<string,XKeywordAction> item = (*miter);
            int len = Buffer.length()-item.first.length();
            len = len<0 ? 0 : len;
            if(Buffer.substr(len)==item.first){
                item.second(&Stack,this->Stream);
                break;
            }
        }
    }while(!this->Stream->eof());
}

void NodeClass::Parse(unordered_map<string, XKeywordAction> m) {

}
