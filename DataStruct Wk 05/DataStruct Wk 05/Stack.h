#pragma once

class Stack
{

	char* list;
	int size;
	int index;

public:

	Stack(int size);
	~Stack();
	bool push(char);
	char pop();
	bool isEmpty();
	bool isFull();

};

