#pragma once
#include "DLCNode.h"
#include <iostream>

using namespace std;

class DoublyLinkedList
{
private:
	int size;
public:
	DLCNode* first;
	DLCNode* last;
	DLCNode* newNode;

	DoublyLinkedList();
	~DoublyLinkedList();
	void addToFront(int data);
	void addToBack(int data);
	void removeFromFront();
	void removeFromBack();
	void removeNode(int);
	void addNode(int index, int data);
	void printReverse(DLCNode* current);
	int get(int index);
	int getSize();

};

