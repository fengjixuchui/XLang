#include "Node.h"
void NodeBase::Parse() {
	string Buffer = "";
	while (!this->Stream->eof()) {
		char charbuf = ' ';
		(*Stream) >> charbuf;
		Buffer.push_back(charbuf);
	}
}