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


string NodeClass::Build() {
    return "class XLClass_"+this->name+"{\n"+Node::Build()+"\n}\n";
};

string NodeCode::Build() {
    return this->code;
}

NodeCode::NodeCode(string _code) {
    this->code = _code;
}

string NodePublic::Build() {
    return "public:\n"+Node::Build();
}

NodeVar::NodeVar(string _name,string _init) {
    this->name = _name;
    this->init = _init;
}

string NodeVar::Build() {
    return "auto *"+ this->name + " = autonew("+(this->init == "","nullptr",this->init)+");\n";
}
