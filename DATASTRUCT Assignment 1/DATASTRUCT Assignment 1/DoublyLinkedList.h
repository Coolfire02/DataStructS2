#pragma once
#include <iostream>

using namespace std;

class DoublyLinkedList
{
	struct DLCNode {
		int data;
		DLCNode* next;
		DLCNode* back;
		DLCNode(int data) : data{ data }, next{ nullptr }, back{ nullptr } {}
	};

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

