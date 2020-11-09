#include "CNode.h"


CNode::CNode() {
	this->link = nullptr;
}

CNode::CNode(int value) {
	this->info = value;
	this->link = nullptr;
}

CNode::~CNode() {

}
