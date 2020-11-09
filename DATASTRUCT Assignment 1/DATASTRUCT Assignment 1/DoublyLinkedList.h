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
	bool removeFromFront();
	bool removeFromBack();
	bool removeNode(int);
	void addNode(int index, int data);
	int get(int index);
	int getSize();

};

