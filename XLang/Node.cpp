#include "Node.h"
void NodeBase::Parse() {
	string Buffer;
    XParserAction Parser = nullptr;
    vector<Node *> Stack;
    Stack.push_back(this);
	while (!this->Stream->eof()) {
	    char i = ' ';
		(*Stream) >> i;
        if(Parser != nullptr){
            Parser(Stack,this->Stream);
            continue;
        }
		Buffer.push_back(i);
		
	}
}