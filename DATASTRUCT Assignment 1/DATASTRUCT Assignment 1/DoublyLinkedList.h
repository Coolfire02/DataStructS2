#pragma once
#include <iostream>
#include <vector>

using namespace std;

class DoublyLinkedList
{
	struct DLCNode {
		char data;
		DLCNode* next;
		DLCNode* back;
		DLCNode(char data) : data{ data }, next{ nullptr }, back{ nullptr } {}
	};

private:
	int size;
public:
	DLCNode* first;
	DLCNode* last;
	DLCNode* newNode;

	DoublyLinkedList();
	~DoublyLinkedList();

	vector<char> toVector();

	void addToFront(char data);
	void addToBack(char data);
	bool removeFromFront();
	bool removeFromBack();
	bool removeNode(int);
	void addNode(int index, char data);
	char get(int index);
	int getSize();

};

