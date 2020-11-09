#pragma once
#include "CNode.h"
#include <iostream>

using namespace std;

class LinkedList
{
private:
	int size;
public:
	CNode* first;
	CNode* last;
	CNode* newNode;

	LinkedList();
	~LinkedList();
	void addToFront(int data);
	void addToBack(int data);
	void removeFromFront();
	void removeFromBack();
	void removeNode(int);
	void addNode(int index, int data);
	void printReverse(CNode* current);
	int get(int index);
	int getSize();

};

