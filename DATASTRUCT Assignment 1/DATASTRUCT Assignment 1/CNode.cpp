#include "CNode.h"

CNode* CNode::getNext() {
	return next;
}

CNode* CNode::getBack() {
	return back;
}

void CNode::setBack(CNode* back) {
	this->back = back;
}

void CNode::setNext(CNode* next) {
	this->next = next;
}

char CNode::getData() {
	return this->data;
}

void CNode::setData(char data) {
	this->data = data;
}