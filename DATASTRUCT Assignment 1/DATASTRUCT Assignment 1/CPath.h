#pragma once
#include "CNode.h"
#include <iostream>
#include <vector>

using namespace std;

class CPath
{

private:
	int size;
public:
	CNode* first;
	CNode* last;
	CNode* newNode;

	CPath();
	~CPath();

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

