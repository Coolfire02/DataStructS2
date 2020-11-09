#pragma once
#include "CNode.h"
class CLinkList
{
private:
	CNode* first, * last, * newNode;
public:
	CLinkList();
	~CLinkList();
	void addToBack(int info);
	void addToFront(int info);
	void deleteFront();
	void deleteBack();
	int get(int index);
	int size();
};

